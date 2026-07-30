class Solution:
    def minimumPushes(self, word: str) -> int:
        assign = 1
        remaining = len(word)
        ans = 0
        loop = remaining // 8
        for _ in range(loop):
            remaining -= 8
            ans += 8 * assign
            assign += 1
        ans += remaining * assign
        return ans
