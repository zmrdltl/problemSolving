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
    void preorder(TreeNode* tree, vector<int> &v){
        if(tree == nullptr) {v.push_back(-1); return;}
        v.push_back(tree->val);
        preorder(tree->left, v);
        preorder(tree->right, v);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector <int> a, b;
        preorder(p, a);
        preorder(q, b);
        if(a.size() != b.size()) return false;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]) return false;
        }
        return true;
    }
};