from collections import deque
from typing import List

class Solution:
  def continuousSubarrays(self, nums: List[int]) -> int:
    answer = 0
    left = 0
    min_queue = deque()
    max_queue = deque()

    for right in range(len(nums)):
        while min_queue and nums[min_queue[-1]] > nums[right]:
            min_queue.pop()
        min_queue.append(right)
        while max_queue and nums[max_queue[-1]] < nums[right]:
            max_queue.pop()
        max_queue.append(right)

        while nums[max_queue[0]] - nums[min_queue[0]] > 2:
            if min_queue[0] == left:
                min_queue.popleft()
            if max_queue[0] == left:
                max_queue.popleft()
            left += 1
            
        answer += right - left + 1

    return answer
