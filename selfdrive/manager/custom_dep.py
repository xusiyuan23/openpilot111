#!/usr/bin/env python3
import os
import sys
import errno
import shutil
import subprocess
from pathlib import Path
from system.hardware import PC

# NOTE: Do NOT import anything here that needs be built (e.g. params)
from common.spinner import Spinner

if not PC:
  THIRD_PARTY_DIR = "/data/third_party_modules"
else:
  THIRD_PARTY_DIR = os.path.join(str(Path.home()), ".comma", "third_party_modules")

sys.path.append(THIRD_PARTY_DIR)
MAX_BUILD_PROGRESS = 100
TOTAL_PIP_STEPS = 100
TMP_DIR = '/data/tmp'
PIP_TARGET = [f'--target={THIRD_PARTY_DIR}']
SCIPY_VERSION = "1.11.1"
OVERPY_VERSION = "0.6"

def param_is_enabled(param="dp_mapd"):
  try:
    from common.params import Params
    with open(Params().get_param_path() + f"/{param}", 'r') as f:
      return f.read() == '1'
  except Exception:
    return False


def scipy_is_valid():
  try:
    import scipy
    if scipy.__version__ != SCIPY_VERSION:
      return False
    return True
  except (ImportError, AttributeError) as e:
    return False


def overpy_is_valid():
  try:
    import overpy
    if overpy.__version__ != OVERPY_VERSION:
      return False
    return True
  except (ImportError, AttributeError) as e:
    return False

MAPD_ACTIVATED = param_is_enabled() and scipy_is_valid() and overpy_is_valid()

def install_dep(spinner):
  try:
    os.makedirs(TMP_DIR)
  except OSError as e:
    if e.errno != errno.EEXIST:
      raise
  my_env = os.environ.copy()
  my_env['TMPDIR'] = TMP_DIR

  packages = []
  if not scipy_is_valid():
    packages.append(f'scipy')
  if not overpy_is_valid():
    packages.append(f'overpy=={OVERPY_VERSION}')

  pip = subprocess.Popen([sys.executable, "-m", "pip", "install", "-U", "--timeout", "10", "-v"] + PIP_TARGET + packages,
                          stdout=subprocess.PIPE, env=my_env)

  # Read progress from pip and update spinner
  steps = 0
  while True:
    output = pip.stdout.readline()
    if pip.poll() is not None:
      break
    if output:
      steps += 1
      spinner.update("Installing mapd dependencies: %s%%" % int(MAX_BUILD_PROGRESS * min(1., steps / TOTAL_PIP_STEPS)))
      print(output.decode('utf8', 'replace'))

  shutil.rmtree(TMP_DIR)
  os.unsetenv('TMPDIR')


if __name__ == "__main__":
  if param_is_enabled() and (not scipy_is_valid() or not overpy_is_valid()):
    spinner = Spinner()
    spinner.update("Installing mapd dependencies (internet required)")
    install_dep(spinner)
    spinner.close()
