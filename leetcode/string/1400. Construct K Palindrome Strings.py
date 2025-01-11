from collections import defaultdict, Counter

class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        if len(s) < k:
            return False
        odd_char_num = 0
        alpha_map = defaultdict(int)
        for char in s:
            alpha_map[char] += 1
        for char, freq in alpha_map.items():
            if freq % 2 == 1:
                odd_char_num += 1
        if odd_char_num > k:
            return False
        return True
