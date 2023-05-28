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
    vector<double> averageOfLevels(TreeNode* root) {
        vector <double> ans;
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int qSize = q.size();
            double avg = 0, nodeNum = qSize;

            while(qSize) {
                TreeNode *frontNode = q.front();
                q.pop();
                qSize--;
                avg += frontNode->val;
                if(frontNode->left) {
                    q.push(frontNode->left);
                }
                if(frontNode -> right) {
                    q.push(frontNode->right);
                }
            }
            ans.push_back(avg/nodeNum);
        }
        
        return ans;
    }
};