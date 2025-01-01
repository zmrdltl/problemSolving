class Solution:
    def maxScore(self, s: str) -> int:
        score = 0
        def getScore(substring, mode):
            return sum(1 for char in substring if char == mode)

        for i in range(1, len(s)):
            left = s[:i]
            right = s[i:]
            score = max(score, getScore(left,'0') + getScore(right,'1'))
        return score
