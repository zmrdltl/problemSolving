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
    vector <int> values;
    void getValues(TreeNode* root) {
        if(root == NULL) return;
        values.push_back(root->val);
        getValues(root->left);
        getValues(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        values.clear();
        getValues(root);
        sort(values.begin(), values.end());
        int ans = 0x3f3f3f3f;
        for(int i = 0; i < values.size() - 1; i++) {
            ans = min(ans, abs(values[i] - values[i+1]));
        }
        return ans;
    }
};