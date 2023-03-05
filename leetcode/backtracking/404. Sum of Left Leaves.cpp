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
#define LEFT 0
#define RIGHT 1
class Solution {
public:
    int getSum(TreeNode*root, int stat) {
        if(root == NULL) return 0;
        int sum = 0;
        sum += getSum(root->left, LEFT) + getSum(root->right, RIGHT);
        if(root->left == NULL && root->right == NULL && stat == LEFT) sum += root->val;
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return getSum(root, RIGHT);
    }
};