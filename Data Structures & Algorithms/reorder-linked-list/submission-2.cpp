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
        if(head == NULL)
            return head;
            
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        ListNode* curr = head;
        while(curr!=NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* mid = reverseList(slow);
        ListNode* curr = head;

        while(mid->next!=NULL)
        {
            ListNode* tempcurr = curr->next;
            ListNode* tempmid = mid->next;

            curr->next = mid;
            mid->next = tempcurr;
            curr = tempcurr;
            mid = tempmid;
        }

    }
};