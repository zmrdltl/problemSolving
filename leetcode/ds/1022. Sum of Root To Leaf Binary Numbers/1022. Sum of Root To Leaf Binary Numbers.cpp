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
    int dfs(TreeNode*root, int prev) {
        if(root == NULL) return 0;
        if(root -> left == NULL && root -> right == NULL) return prev*2+root->val; //말단 답 반환
        return dfs(root->right, prev*2+root->val) + dfs(root->left, prev*2+root->val);
    }
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root,0);
    }
};