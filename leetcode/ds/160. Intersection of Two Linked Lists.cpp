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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int aLength = 0;
        int bLength = 0;
        
        ListNode *aCur = headA;
        ListNode *bCur = headB;

        for(ListNode *cnt = headA; cnt != NULL; cnt = cnt -> next) aLength++;
        for(ListNode *cnt = headB; cnt != NULL; cnt = cnt -> next) bLength++;

        int minLength = min(aLength, bLength);

        for(int i = 0; i < aLength - minLength; i++) aCur = aCur->next;
        for(int i = 0; i < bLength - minLength; i++) bCur = bCur->next;

        while(aCur != NULL && bCur != NULL) {
            if(aCur == bCur) return aCur;
            aCur = aCur -> next;
            bCur = bCur -> next;
        }

        return NULL;
    }
};