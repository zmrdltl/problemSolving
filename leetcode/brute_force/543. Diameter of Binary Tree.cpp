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
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        go(root);
        return ans;
    }
    int go (TreeNode* root) {
        if(root == NULL) return 0;
        int left = go(root->left);
        int right = go(root->right);
        ans = max(ans, left + right);
        return max(left,right) + 1;
    }
};