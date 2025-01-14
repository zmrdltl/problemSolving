from collections import defaultdict
class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        b_map = defaultdict(int)
        length = len(A)
        for i in range(length):
            b_map[B[i]] = i
        ans = []
        for i in range(length):
            cnt = 0
            for j in range(i+1):
                if b_map.get(A[j]) <= i:
                    cnt += 1
            ans.append(cnt)
        return ans
