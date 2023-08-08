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
    int getMiddleIndex(ListNode*head){
        ListNode * cur = head;
        int totalIndex = 0;
        while(cur != NULL) {
            totalIndex++;
            cur = cur->next;
        }
        return totalIndex/2;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode*ans = head;
        int cnt = 0;
        int middleIndex = getMiddleIndex(head);
        while(cnt != middleIndex) {
            ans=ans->next;
            cnt++;
        }
        return ans;
    }
};