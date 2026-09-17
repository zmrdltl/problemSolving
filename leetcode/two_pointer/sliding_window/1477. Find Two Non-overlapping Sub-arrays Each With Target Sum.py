class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        total,left = 0,0
        n = len(arr)
        INF = n + 1
        ans = INF
        best = [INF] * (n+1)
        for right,x in enumerate(arr):
            total += x
            while total > target:
                total -= arr[left]
                left+=1
            best[right+1] = best[right]
            if total == target:
                length = right - left + 1
                ans = min(ans, best[left] + length)
                best[right+1] = min(best[right+1], length)
        return -1 if ans == INF else ans
