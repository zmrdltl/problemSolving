from bisect import bisect_left

class Solution:
  def canChange(self, start: str, target: str) -> bool:
    start_char_idx = [(i,char) for i,char in enumerate(start) if char != '_']
    target_char_idx = [(i,char) for i,char in enumerate(target) if char != '_']

    if len(start_char_idx) != len(target_char_idx):
        return False
    if any(s[1] != t[1] for s, t in zip(start_char_idx, target_char_idx)):
        return False
    for (start_idx, start_char), (target_idx, _) in zip(start_char_idx, target_char_idx):
        if start_char == 'L' and start_idx < target_idx:
            return False
        elif start_char == 'R' and start_idx > target_idx:
            return False
    return True