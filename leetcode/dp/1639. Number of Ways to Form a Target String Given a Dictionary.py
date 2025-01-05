from collections import defaultdict
class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        MOD = 10**9 + 7
        word_len = len(words[0])
        target_len = len(target)
        freq_map = [defaultdict(int) for _ in range(word_len)]
        for word in words:
            for j, char in enumerate(word):
                freq_map[j][char] += 1
        total_ways = [[-1]*word_len for _ in range(target_len)]
        def dp(j, k):
            if j == target_len:
                return 1
            if k == word_len:
                return 0
            if total_ways[j][k] != -1:
                return total_ways[j][k]
            ways = dp(j,k+1)
            ways += freq_map[k][target[j]] * dp(j+1,k+1) % MOD
            total_ways[j][k] = ways % MOD
            return total_ways[j][k]
        return dp(0, 0)
