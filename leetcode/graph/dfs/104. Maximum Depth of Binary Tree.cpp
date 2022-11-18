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
    int dfs(TreeNode* tree, int depth) {
        if(tree == nullptr) return 0;
        return max(dfs(tree->left, depth + 1), dfs(tree->right, depth + 1)) + 1;
    }
    
    int maxDepth(TreeNode* root) {
        return dfs(root, 1);
    }
};