class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        length = len(nums)
        sums = [0] * length
        sums[0] = nums[0]
        valid_splits = 0
        for i in range(1, length):
            sums[i] = nums[i] + sums[i-1]
        for i in range(0, length-1):
            left_sum = sums[i]
            right_sum = sums[length-1] - sums[i]
            if left_sum >= right_sum:
                valid_splits += 1
        return valid_splits
