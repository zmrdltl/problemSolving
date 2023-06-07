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
    void preOrder(TreeNode* root) {
        if(root == NULL) return;
        s.insert(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        preOrder(root);
        vector <int> setVec(s.begin(), s.end());
        if(setVec.size() == 1) return -1;
        return setVec[1]; 
    }
};