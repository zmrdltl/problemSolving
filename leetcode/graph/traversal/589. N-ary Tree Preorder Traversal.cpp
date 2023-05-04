/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if(root == NULL) return vector<int>();
        vector <int> ans;
        ans.push_back(root->val);
        for(auto c : root->children) {
            vector <int> a = preorder(c);
            ans.insert(ans.end(), a.begin(), a.end());
        }
        return ans;
    }
};