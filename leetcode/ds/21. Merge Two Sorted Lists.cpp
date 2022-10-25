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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *cur = list1;
        vector <int> vals;
        while(cur != nullptr) {
            vals.push_back(cur->val);
            cur = cur->next;
        }
        cur = list2;
        while(cur != nullptr) {
            vals.push_back(cur->val);
            cur = cur->next;
        }
        
        if(!vals.size()) return nullptr;
        sort(vals.begin(), vals.end());
        
        ListNode *ans = new ListNode(vals[0]);
        cur = ans;
        for(int i = 1; i < vals.size(); i++) {
            ListNode *next = new ListNode(vals[i]);
            cur -> next = next;
            cur = cur->next;
        }
        return ans;
    }
};