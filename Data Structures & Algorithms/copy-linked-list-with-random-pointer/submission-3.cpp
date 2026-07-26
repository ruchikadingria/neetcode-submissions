/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* it = head;

        if(head == NULL)
            return NULL;

        while(it != nullptr)
        {
            Node* newNode = new Node(it->val);
            newNode->next = it->next;
            it->next = newNode;
            it = it->next->next;
        }

        it = head;
        while(it != nullptr)
        {
            Node* clonedNode = it->next;
            clonedNode->random = (it->random) ? it->random->next : nullptr;
            it = it->next->next;
        }

        it = head;
        Node* clonedHead = head->next;
        while(it != nullptr)
        {
            Node* clonedNode = it->next;
            it->next = clonedNode->next;
            if(clonedNode->next != nullptr)
                clonedNode->next = clonedNode->next->next;
            it = it->next;
        }
        return clonedHead;
    }
};
