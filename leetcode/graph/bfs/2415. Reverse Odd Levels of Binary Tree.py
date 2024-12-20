from collections import deque

class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        dq = deque([root])
        level = 0
        while dq:
            cur_level_size = len(dq)
            cur_level_values = []
            level += 1

            for _ in range(cur_level_size):
                cur_node = dq.popleft()
                if cur_node.left and cur_node.right:
                    dq.append(cur_node.left)
                    dq.append(cur_node.right)
                    if level % 2 == 1:
                        cur_level_values.append(cur_node.left.val)
                        cur_level_values.append(cur_node.right.val)
            if level % 2 == 1:
                for i in range(len(dq)):
                    if cur_level_values:
                        dq[i].val = cur_level_values.pop()
        return root
