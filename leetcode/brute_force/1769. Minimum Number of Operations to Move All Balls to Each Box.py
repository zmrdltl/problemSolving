class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        answer = []

        for i, box in enumerate(boxes):
            op = 0

            for j, box in enumerate(boxes):
                if box == '1':
                    op += abs(i-j)
            answer.append(op)

        return answer
