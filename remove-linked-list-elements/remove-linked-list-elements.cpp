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
        if(!head)
            return NULL;
        
        while(head && head->val == val)
            head = head->next;
        
        ListNode *l = head;
        while(l && l->next){
            if(l->next->val == val)
                l->next = l->next->next;
            else
                l = l->next;
        }
        return head;
    }
};