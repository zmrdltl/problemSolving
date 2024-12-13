from heapq import heappush, heappop
class Solution:
    def findScore(self, nums: List[int]) -> int:
        pq = []
        score = 0
        ck = [0] * len(nums)
        for i, n in enumerate(nums):
            heappush(pq,(n,i))
        while pq:
            num, index = heappop(pq)
            if ck[index] == 1:
                continue
            score += num
            ck[index] = 1
            if index - 1 >= 0:
                ck[index-1] = 1
            if index + 1 < len(nums):
                ck[index+1] = 1

        return score