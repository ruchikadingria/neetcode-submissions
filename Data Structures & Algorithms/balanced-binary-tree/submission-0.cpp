/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        int leftHeight = maxDepth(root->left) + 1;
        int rightHeight = maxDepth(root->right) + 1;
        return max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;

        int leftHeight = maxDepth(root->left);    
        int rightHeight = maxDepth(root->right);
        if(abs(leftHeight - rightHeight) > 1)
            return false;
        else {
            bool left = isBalanced(root->left);
            bool right = isBalanced(root->right);
            if(left && right)
                return true;
            else
                return false;
        }    
    }
};
