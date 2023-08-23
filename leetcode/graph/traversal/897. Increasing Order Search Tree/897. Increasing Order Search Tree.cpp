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
    void inOrder(TreeNode* root, vector <int> &nodes) {
        if(root == NULL) return;
        inOrder(root->left, nodes);
        nodes.push_back(root->val);
        inOrder(root->right, nodes);
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector <int> nodes;
        inOrder(root, nodes);

        TreeNode *ans = new TreeNode();
        TreeNode *cur = ans;
        for(auto node : nodes) {
            TreeNode *newNode = new TreeNode(node);
            cur -> right = newNode;
            cur = cur -> right;
        }
        return ans->right;
    }
};