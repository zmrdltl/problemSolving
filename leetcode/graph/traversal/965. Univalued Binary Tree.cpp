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
    set <int> s;
    void preOrder(TreeNode* root){
        if(root == NULL) return;
        s.insert(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        s.clear();
        preOrder(root);
        return s.size() == 1;
    }
};