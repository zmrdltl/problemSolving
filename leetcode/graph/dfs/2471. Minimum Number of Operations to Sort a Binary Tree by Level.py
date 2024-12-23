from collections import deque
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        def minCicle(values):
            n = len(values)
            visited = [False] * n
            sortedValIdx = sorted([(value, idx) for idx, value in enumerate(values)])
            swaps = 0
            for i in range(n):
                if visited[i] or sortedValIdx[i][1] == i:
                    continue
                cycleSize = 0
                x = i
                while not visited[x]:
                    visited[x] = True
                    x = sortedValIdx[x][1]
                    cycleSize += 1
                if cycleSize > 1:
                    swaps += (cycleSize - 1)
            return swaps

        totalSwap = 0
        dq = deque([root])
        while dq:
            size = len(dq)
            values = []
            for i in range(size):
                front = dq.popleft()
                values.append(front.val)
                if front.left:
                    dq.append(front.left)
                if front.right:
                    dq.append(front.right)
            totalSwap += minCicle(values)

        return totalSwap
