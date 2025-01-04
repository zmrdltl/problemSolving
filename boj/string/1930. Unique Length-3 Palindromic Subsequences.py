from collections import defaultdict
class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        letters = set(s)
        ans = 0
        for ch in letters:
            i, j = s.index(ch), s.rindex(ch)
            between = set()
            for k in range(i+1, j):
                between.add(s[k])
            ans += len(between)
        return ans
