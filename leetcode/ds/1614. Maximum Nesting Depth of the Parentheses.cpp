class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        stack <char> st;
        for(auto c : s) {
            if(c == ')') {
                depth = max(depth, (int)st.size());
                st.pop();
            } else if(c == '(') {
                st.push(c);
            }
        }
        return depth;
    }
};