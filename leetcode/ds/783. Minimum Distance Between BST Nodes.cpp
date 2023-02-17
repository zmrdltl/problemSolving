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
    vector<int> nums;

    void inorder(TreeNode* root) {
        if(root == NULL) return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        inorder(root);
        sort(nums.begin(), nums.end());
        int ret = 0x3f3f3f3f;
        for(int i = 0; i < nums.size()-1; i++) {
            ret = min(ret, nums[i+1] - nums[i]);
        }
        return ret;
    }
};
