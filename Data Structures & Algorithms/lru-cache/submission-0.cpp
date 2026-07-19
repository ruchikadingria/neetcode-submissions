class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            val = v;
            next = prev = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> m;
    int limit;

    LRUCache(int capacity) {
        limit = capacity;

        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode)
    {
        Node* oldNext = head->next;

        head->next = newNode;
        oldNext->prev = newNode;

        newNode->prev = head;
        newNode->next = oldNext;
    }

    void delNode(Node* oldNode)
    {
        Node* oldNext = oldNode->next;
        Node* oldPrev = oldNode->prev;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;

        oldNode->prev = NULL;
        oldNode->next = NULL;
    }

    int get(int key) {
        if(m.find(key) == m.end())
            return -1;

        Node* ansNode = m[key];
        int ans = ansNode->val;

        delNode(ansNode);
        addNode(ansNode);

        return ans;
    }

    void put(int key, int value) {
        if(m.find(key) != m.end())
        {
            Node* oldNode = m[key];
            oldNode->val = value;

            delNode(oldNode);
            addNode(oldNode);

            return;
        }

        if(m.size() == limit)
        {
            Node* oldNode = tail->prev;
            m.erase(oldNode->key);
            delNode(oldNode);
            delete oldNode;
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};