class Solution:
    def smallestPalindrome(self, s: str) -> str:
        d = {}

        for ch in s:
            d[ch] = d.get(ch, 0) + 1

        left = ""
        middle = ""

        for ch, count in sorted(d.items()):
            left += ch * (count // 2)
            if count % 2 == 1:
                middle = ch

        return left + middle + left[::-1]
