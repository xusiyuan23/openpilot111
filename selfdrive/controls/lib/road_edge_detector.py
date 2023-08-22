import numpy as np

class RoadEdgeDetector:

  def __init__(self):
    self._is_enabled = False

  def get_road_edge_detected(self, road_edge_stds, lane_line_probs, left_blinker, right_blinker):
    if not self._is_enabled:
      return False, False

    # Calculate probabiities for detecting road edges and lane lines
    left_road_edge_prob = np.clip(1.0 - road_edge_stds[0], 0.0, 1.0)
    left_lane_nearside_prob = lane_line_probs[0]

    right_road_edge_prob = np.clip(1.0 - road_edge_stds[1], 0.0, 1.0)
    right_lane_nearside_prob = lane_line_probs[3]

    # Check conditions for detecting road edges
    if right_blinker and right_road_edge_prob > 0.35 and right_lane_nearside_prob < 0.2 and left_lane_nearside_prob >= right_lane_nearside_prob:
      return False, True
    if left_blinker and left_road_edge_prob > 0.35 and left_lane_nearside_prob < 0.2 and right_lane_nearside_prob >= left_lane_nearside_prob:
      return True, False

    return False, False

  def set_enabled(self, enabled):
    self._is_enabled = enabled

  def is_enabled(self):
    return self._is_enabled
