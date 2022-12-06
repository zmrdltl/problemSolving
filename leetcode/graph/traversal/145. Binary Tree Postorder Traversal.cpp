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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return vector<int>();
        vector <int> v;
        vector <int> a = postorderTraversal(root->left);
        vector <int> b = postorderTraversal(root->right);
        v.insert(v.begin(), b.begin(), b.end());
        v.insert(v.begin(), a.begin(), a.end());
        v.push_back(root->val);
        return v;
    }
};