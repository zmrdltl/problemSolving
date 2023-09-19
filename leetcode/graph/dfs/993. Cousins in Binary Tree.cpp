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
struct Info {
    int depth; TreeNode *parent;
};
class Solution {
public:
    void dfs(TreeNode*root, TreeNode*parent, int x, int y, int depth, Info &xInfo, Info &yInfo) {
        if(root == NULL) return;
        if(x == root->val) {
            xInfo = {depth,parent};
        }
        if(y == root->val) {
            yInfo = {depth, parent};
        }
        dfs(root->left, root, x, y, depth + 1, xInfo, yInfo);
        dfs(root->right, root, x, y, depth + 1, xInfo, yInfo);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        Info xInfo = {-1, NULL};
        Info yInfo = {-1, NULL};
        dfs(root, root, x, y, 0, xInfo, yInfo);
        return  xInfo.depth == yInfo.depth && xInfo.parent != yInfo.parent;
    }
};