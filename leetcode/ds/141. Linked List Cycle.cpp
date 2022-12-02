/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* cur = head;
        while(cur != NULL) {
            if(cur->val == -0x3f3f3f3f)
                return true;
            cur->val = -0x3f3f3f3f;
            cur = cur->next;
        }
        return false;
    }
};