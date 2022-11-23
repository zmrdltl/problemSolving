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
    int getHeight(TreeNode* node){
        if(node == NULL) return 0;
        return max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int diff = abs(getHeight(root->left) - getHeight(root->right));
        if(diff > 1) return false;
        return min(isBalanced(root->left), isBalanced(root->right));
    }
};