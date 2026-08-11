class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        prefix_sum = nums[0]
        for i in range(1, len(nums)):
            if nums[i] != nums[i-1] + 1:
                break
            else:
                prefix_sum += nums[i]
        num_set = set(nums)
        while prefix_sum in num_set:
            prefix_sum += 1
        return prefix_sum
