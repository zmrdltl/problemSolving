from bisect import insort
class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        length = len(values)
        sorted_values = []
        max_score = 0
        for j in range(len(values)):
            if sorted_values:
                max_i = sorted_values[-1]
                max_score = max(max_score, max_i + values[j] - j)

            insort(sorted_values, values[j] + j)
        return max_score
