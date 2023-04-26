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
    vector <int> getPreOrdered(TreeNode* tree){
        if(tree == NULL) return vector<int>();
        vector<int> left = getPreOrdered(tree->left);
        left.push_back(tree->val);
        vector<int> right = getPreOrdered(tree->right);
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;
        if(root->val == subRoot->val) {
            vector <int> v = getPreOrdered(root);
            vector <int> v1 = getPreOrdered(subRoot);
            if(v == v1) return true;
        }
        return max(isSubtree(root->left, subRoot), isSubtree(root->right, subRoot));
    }
};