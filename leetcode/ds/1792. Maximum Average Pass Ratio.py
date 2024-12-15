from heapq import heappush, heappop

class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        avg = 0
        classes.sort()
        pq = []
        for idx, [passed, total] in enumerate(classes):
            cur_ratio = passed/total
            if cur_ratio == 1.0:
                continue
            expected_ratio = (passed+1)/(total+1) - cur_ratio
            heappush(pq, (-expected_ratio, cur_ratio, idx))

        for _ in range(extraStudents):
            if not pq:
                break
            expected_ratio, cur_ratio, idx = heappop(pq)
            expected_ratio = -expected_ratio
            passed, total = classes[idx][0] + 1, classes[idx][1] + 1
            classes[idx] = [passed, total]
            cur_ratio += expected_ratio
            expected_ratio = (passed+1)/(total+1) - cur_ratio
            heappush(pq, (-expected_ratio, cur_ratio, idx))

        for c in classes:
            avg += c[0] / c[1]
        return round(avg / len(classes), 5)