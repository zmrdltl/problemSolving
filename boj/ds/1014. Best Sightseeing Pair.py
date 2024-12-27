from heapq import heappush, heappop
class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        length = len(values)
        sorted_values = []
        max_score = 0
        for j in range(len(values)):
            if sorted_values:
                max_i = heappop(sorted_values)
                max_i = -max_i
                heappush(sorted_values, -max_i)
                max_score = max(max_score, max_i + values[j] - j)

            heappush(sorted_values, -(values[j] + j))
        return max_score
