from collections import Counter

class Solution:
    def minimumLength(self, s: str) -> int:
        length = len(s)
        if length < 2:
            return length
        s_counter = Counter(s)
        ans = 0
        for _, freq in s_counter.items():
            if freq < 2:
                ans += freq
            elif freq % 2 == 0:
                ans += 2
            elif freq % 2 == 1:
                ans += 1
        return ans
