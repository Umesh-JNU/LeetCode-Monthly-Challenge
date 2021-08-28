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
    bool isPalindrome(ListNode *head)
    {
        if(!head->next)
            return true;

        ListNode *slow = head;
        ListNode *fast = head;
        // reaching mid node
        while (fast && fast->next)
        {
            // cout << slow->val << endl;
            fast = fast->next->next;
            slow = slow->next;
        }

        // cout << (fast != NULL) << slow->val << endl;

        // reversing first half
        ListNode *prev = NULL, *nxt = NULL, *cur = head;
        while (cur != slow)
        {
            // cout << cur->val << endl;
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        // making even partition
        if(fast)
            slow = slow->next;

        // comparing
        while(prev && slow){
            if(slow->val != prev->val)
                return false;
            prev = prev->next;
            slow = slow->next;
        }

        return true;
    }
};