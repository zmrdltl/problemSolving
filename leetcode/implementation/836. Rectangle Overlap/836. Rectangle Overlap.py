class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        x1, y1, x2, y2 = rec1[0], rec1[1], rec1[2], rec1[3]
        a1, b1, a2, b2 = rec2[0], rec2[1], rec2[2], rec2[3]

        return (
            x1 < a2 and
            a1 < x2 and
            y1 < b2 and
            b1 < y2
        )
