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

/*
Input ：l1 = [2,4,3], l2 = [5,6,4]
Output：[7,0,8]
Doing ：342 + 465 = 807.

The head node of l1 or l2 is the most small base of num just like '2' and '5' .
So we need to compute the sum of them and discuss if the carry is exist.
sum = val1 + val2 + carry ;
carry = sum / 10;
Origin bit = sum % 10;
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr, *tail = nullptr;
        int carry = 0;
        while(l1 || l2)
        {
            int val_l1 = l1 ? l1->val : 0;
            int val_l2 = l2 ? l2->val : 0;
            int sum = val_l1 + val_l2 + carry;
            if(!head)
            {
                head = tail = new ListNode(sum % 10);
            }else{
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if(l1)  l1 = l1->next;
            if(l2)  l2 = l2->next;
        }
        if(carry)
            tail->next = new ListNode(carry);
        return head;
    }
};
