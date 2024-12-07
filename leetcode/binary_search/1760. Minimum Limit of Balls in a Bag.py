class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        left, right = 1, max(nums)
        while left < right:
            mid = (left + right) // 2
            tot = sum((x-1)//mid for x in nums)
            if tot <= maxOperations:
                right = mid
            else:
                left = mid + 1
        return right