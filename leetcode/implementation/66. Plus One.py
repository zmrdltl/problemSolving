class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        sum = 0
        for i in range(len(digits)):
            sum += digits[i]
            sum *= 10
        sum = sum // 10 + 1
        sum = list(map(int, str(sum)))
        return sum