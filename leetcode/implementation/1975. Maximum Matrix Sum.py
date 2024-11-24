class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        r = len(matrix)
        c = len(matrix[0])
        minus_count = 0
        min_abs_num = 0x3f3f3f3f
        sum = 0
        for i in range(r):
            for j in range(c):
                value = matrix[i][j]
                if value < 0:
                    minus_count += 1
                sum += abs(value)
                min_abs_num = min(min_abs_num, abs(value))
        if minus_count % 2 == 0:
            return sum
        return sum - min_abs_num * 2