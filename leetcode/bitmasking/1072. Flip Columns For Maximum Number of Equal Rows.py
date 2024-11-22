from collections import Counter
class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        def nomalize(row):
            return tuple(r ^ row[0] for r in row)
        pattern = Counter(nomalize(row) for row in matrix)
        return max(pattern.values())