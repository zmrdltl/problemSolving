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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return isValid(root, targetSum, 0);
    }
    
    bool isValid(TreeNode* node, int targetSum, int sum) {
        if(node == NULL) {
            return false;
        }
        if(node->left == NULL && node->right == NULL){
            if(targetSum == sum + node->val) return true;
            return false;
        }
        bool isLeftValid = isValid(node->left, targetSum, sum + node->val);
        bool isRightValid = isValid(node->right, targetSum, sum + node->val);
        return max(isLeftValid, isRightValid);
    }
};
