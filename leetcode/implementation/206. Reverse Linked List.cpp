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
    ListNode* reverseList(ListNode* head) {
        vector <int> v;
        while(head != NULL) {
            v.push_back(head -> val);
            head = head -> next;
        }
        ListNode* node = new ListNode();
        ListNode* ans = node;
        for(int i = v.size() - 1; i >= 0; i--) {
            ListNode* newNode = new ListNode(v[i]);
            node -> next = newNode;
            node = node -> next;
        }
        
        return ans->next;
    }
};