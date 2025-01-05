from collections import defaultdict
class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        MOD = 10**9 + 7
        ck = {}
        answer = 0

        # dp = [0] * (high+1)
        # dp[0] = 1

        # for i in range(1, high + 1):
        #     if i - zero >= 0:
        #         dp[i] += dp[i-zero]
        #     if i - one >= 0:
        #         dp[i] += dp[i-one]
        #     dp[i] %= MOD
        # for i in range(low, high + 1):
        #     answer = (answer+dp[i]) % MOD

        memo ={}
        def dp(length):
            if length > high:
                return 0
            if length in memo:
                return memo[length]
            count = 1 if length >= low else 0
            count += dp(length+one)
            count += dp(length+zero)
            count %= MOD

            memo[length] = count
            return count
        return dp(0)
