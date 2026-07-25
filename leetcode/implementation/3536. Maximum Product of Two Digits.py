class Solution:
    def maxProduct(self, n: int) -> int:
        digits = sorted(map(int, str(n)), reverse=True)
        return digits[0] * digits[1]
