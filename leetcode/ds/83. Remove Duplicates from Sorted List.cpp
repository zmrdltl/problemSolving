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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        ListNode *ans = cur;
        set <int> s;
        
        while(cur != nullptr){
            s.insert(cur->val);
            cur = cur->next;
        }
        
        if(!s.size()) return nullptr;
        
        cur = ans;
        
        for(auto e : s) {
            ListNode *ne = new ListNode();
            ne -> val = e;
            ans -> next = ne;
            ans = ans->next;
        }
        return cur->next;
    }
};
