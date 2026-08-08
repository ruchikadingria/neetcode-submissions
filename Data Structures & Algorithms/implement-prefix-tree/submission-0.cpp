class TrieNode {
   public:
    char data;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;

    TrieNode(char val) {
        data = val;
        isTerminal = false;
    }
};

class PrefixTree {
   public:
    TrieNode* root;

    PrefixTree() { root = new TrieNode('-'); }

    void insertWord(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        char ch = word[0];

        TrieNode* child;
        if (root->children.find(ch) != root->children.end())
            child = root->children[ch];
        else {
            TrieNode* newNode = new TrieNode(ch);
            root->children[ch] = newNode;
            child = newNode;
        }

        insertWord(child, word.substr(1));
    }

    bool searchWord(TrieNode* root, string word) {
        if (word.length() == 0) return root->isTerminal;

        char ch = word[0];
        TrieNode* child;

        if (root->children.find(ch) != root->children.end())
            child = root->children[ch];
        else {
            return false;
        }

        return searchWord(child, word.substr(1));
    }

    bool searchPrefix(TrieNode* root, string word) {
        if (word.length() == 0) return true;

        char ch = word[0];
        TrieNode* child;

        if (root->children.find(ch) != root->children.end())
            child = root->children[ch];
        else {
            return false;
        }

        return searchPrefix(child, word.substr(1));
    }

    void insert(string word) { insertWord(root, word); }

    bool search(string word) { return searchWord(root, word); }

    bool startsWith(string prefix) { return searchPrefix(root, prefix); }
};
