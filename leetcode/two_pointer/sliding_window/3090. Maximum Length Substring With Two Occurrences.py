class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        l,r,ans = 0,0,0
        freq = {}
        while r < len(s):
            freq[s[r]] = freq.get(s[r],0) + 1
            while freq[s[r]] > 2:
                freq[s[l]] -= 1
                l += 1
            r += 1
            ans = max(ans, r-l)
        return ans
