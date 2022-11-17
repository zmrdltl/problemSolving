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
    void inOrder(TreeNode* tree, vector <int> &v, int depth){
        if(tree == nullptr) { return;}
        inOrder(tree->left, v, depth + 100);
        v.push_back(tree->val + depth);
        inOrder(tree->right, v, depth + 100);
    }
    
    bool isSymmetric(TreeNode* root) {
        vector <int> v;
        inOrder(root, v, 0);
        for(int i = 0; i < v.size() / 2; i++) {
            if(v[i] != v[v.size() - i - 1]) return false;
        }
        return true;
    }
};