# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:

        def num_of_linked_list(linked_list: Optional[ListNode]):
            num = 0
            piv = 0
            cur = linked_list
            while cur:
                num += cur.val * 10**piv
                cur = cur.next
                piv += 1
            return num

        def make_linked_list(n: int):
            if n == 0:
                return None
            list_node = ListNode(n%10)
            list_node.next = make_linked_list(n//10)
            return list_node

        num = num_of_linked_list(l1) + num_of_linked_list(l2)
        ans = make_linked_list(num)
        if not ans:
            return ListNode()
        return ans
