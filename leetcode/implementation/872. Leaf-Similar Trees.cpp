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
    vector <int> nodes;
    
    void collectLeaves(TreeNode* tree) {
        if(tree == NULL) return;
        if(tree->left == NULL && tree->right == NULL) {
            nodes.push_back(tree->val);
            return;
        }
        collectLeaves(tree->left);
        collectLeaves(tree->right);
        return;
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        collectLeaves(root1);
        vector <int> nodes1 = nodes;
        nodes.clear();
        collectLeaves(root2);
        vector <int> nodes2 = nodes;
        nodes.clear();
        if(nodes1.size() != nodes2.size()) return false;
        for(int i = 0; i < nodes1.size(); i++) {
            if(nodes1[i] != nodes2[i]) return false;
        }
        return true;
    }
};