class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        nums_set = set(nums)
        ans = []
        for num in range(min(nums), max(nums)):
            if num not in nums_set:
                ans.append(num)
        return ans
