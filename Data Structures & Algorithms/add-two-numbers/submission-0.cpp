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
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* newHead = NULL;
        ListNode* newTail = NULL;

        int carry = 0;
        while(temp1 || temp2 || carry)
        {
            int first = (temp1) ? temp1->val : 0;
            int second = (temp2) ? temp2->val : 0;

            int sum = first + second + carry;
            carry = sum / 10;
            int digit = sum % 10;

            ListNode* newNode = new ListNode(digit);

            if(!newHead)
            {
                newHead = newNode;
                newTail = newNode;
            }
            else{
                newTail->next = newNode;
                newTail = newNode;
            }

            if(temp1)
                temp1 = temp1->next;

            if(temp2)
                temp2 = temp2->next;
        }
        return newHead;
    }
};
