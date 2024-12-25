from collections import deque
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        dq = deque([root])

        max_values = []
        while dq:
            size = len(dq)
            max_value = float('-inf')
            for i in range(size):
                node = dq.popleft()
                max_value = max(max_value,node.val)
                if node.left:
                    dq.append(node.left)
                if node.right:
                    dq.append(node.right)

            max_values.append(max_value)

        return max_values
