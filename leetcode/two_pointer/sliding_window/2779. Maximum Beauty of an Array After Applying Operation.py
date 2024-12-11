class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        nums.sort()
        left = 0
        num_len = len(nums)
        max_length = 0
            
        for right in range(num_len):
            if nums[right] - nums[left] > 2 * k:
                left += 1
            max_length = max(max_length, right - left + 1)
        return max_length
