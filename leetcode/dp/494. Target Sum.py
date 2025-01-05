class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        depth = len(nums)
        memo = {}
        def dfs(n: int, num: int):
            if n == depth:
                if num == target:
                    return 1
                return 0
            if (n, num) in memo:
                return memo[(n, num)]
            memo[(n,num)] = dfs(n + 1, num + nums[n]) + dfs(n+1, num - nums[n])

            return memo[(n,num)]
        return dfs(0, 0)
