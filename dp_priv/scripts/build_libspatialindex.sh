#!/usr/bin/env bash
set -e

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" >/dev/null && pwd)"/../../third_party/libspatialindex

ARCHNAME=$(uname -m)
if [ -f /TICI ]; then
  ARCHNAME="larch64"
fi

if [[ "$OSTYPE" == "darwin"* ]]; then
  ARCHNAME="Darwin"
fi

cd $DIR

if [ ! -d libspatialindex ]; then
  git clone --single-branch https://github.com/libspatialindex/libspatialindex
fi

cd libspatialindex

# build
rm -fr build
mkdir build
cd build
cmake ..
cmake --build . -j$(nproc)

rm -fr $DIR/$ARCHNAME
mkdir -p $DIR/$ARCHNAME

make install DESTDIR=$DIR/$ARCHNAME

# clean up
rm -fr $DIR/libspatialindex/
mv $DIR/$ARCHNAME/usr/local/* $DIR/$ARCHNAME
rm -fr $DIR/$ARCHNAME/usr/
rm -fr $DIR/$ARCHNAME/lib/cmake/
rm -fr $DIR/$ARCHNAME/lib/pkgconfig/