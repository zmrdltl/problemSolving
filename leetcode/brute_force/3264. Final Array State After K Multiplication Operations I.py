class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        for _ in range(k):
            min_num_idx = nums.index(min(nums))
            nums[min_num_idx] *= multiplier
        return nums