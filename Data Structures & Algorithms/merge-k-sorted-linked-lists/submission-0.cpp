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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        
        vector<int> nums;
        for(int i = 0; i < lists.size(); i++)
        {
            ListNode* node = lists[i];
            while(node!=nullptr)
            {
                nums.push_back(node->val);
                node = node->next;
            }
        }
        
        if(nums.empty())
            return nullptr;
            
        sort(nums.begin(), nums.end());

        ListNode* head = new ListNode(nums[0]);
        ListNode* temp = head;

        int count = 1;
        while(count < nums.size())
        {
            ListNode* newNode = new ListNode(nums[count]); 
            temp->next = newNode;
            count++;
            temp = temp->next;
        }
        return head;
    }
};