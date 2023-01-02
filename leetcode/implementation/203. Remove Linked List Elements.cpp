/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *deletedNode = head;
        while(deletedNode != NULL && deletedNode->val == val) {
            deletedNode = deletedNode->next;
        }
        ListNode *cur = deletedNode;
        ListNode *prev = deletedNode;
        while(cur != NULL) {
            if(cur->val == val) {
                while(cur != NULL && cur->val == val) {
                    cur = cur->next;
                }
                prev->next = cur;
                continue;
            }
            prev = cur;
            cur = cur->next;
        }
        return deletedNode;
    }
};