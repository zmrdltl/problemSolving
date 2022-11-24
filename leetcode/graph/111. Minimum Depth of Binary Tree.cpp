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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        if(left == NULL && right == NULL) return 1;
        if(left != NULL && right == NULL) return minDepth(left) + 1;
        if(left == NULL && right != NULL) return minDepth(right) + 1;
        return min(minDepth(left), minDepth(right)) + 1;
    }
};