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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1=l1, *t2=l2;
        stack<int> s1, s2;
        while(t1){
            // cout << t1->val << endl;
            s1.push(t1->val);
            t1 = t1->next;
        }
        // cout << "------------" << endl;
        while(t2){
            // cout << t2->val << endl;
            s2.push(t2->val);
            t2 = t2->next;
        }
        // cout << "------------" << endl;
        ListNode* head = NULL, *t=NULL;
        int carry=0, sum;
        while(1){
            if(!s1.empty() && !s2.empty()){
                // cout << s1.top() << " " << s2.top() << endl;
                sum = s1.top() + s2.top()+carry;
                s1.pop(); s2.pop();
            }
            else{
                if(s2.empty() && s1.empty()){
                    if(carry){
                        t = new ListNode(carry);
                        t->next = head;
                        head = t;
                    }
                    break;
                }
                else if(s2.empty()){
                    // cout << s1.top() << endl;
                    sum = s1.top()+carry;
                    s1.pop();
                }          
                else if(s1.empty()){
                    // cout << s2.top() << endl;
                    sum = s2.top()+carry;
                    s2.pop();
                }
            }
            carry = sum/10;
            sum = sum % 10;

            t = new ListNode(sum);
            t->next = head;
            head = t;
            // cout << "head->val = " << head->val << endl;
        }
        
        // t = head;
        // while(t){
        //     cout << t->val << endl;
        //     t = t->next;
        // }
        return head;
    }
};