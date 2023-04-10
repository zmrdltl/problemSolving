class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(auto c : s) {
            if(st.size()) {
                if(st.top() == '(' && c == ')') {
                    st.pop();
                    continue;
                }
                if(st.top() == '{' && c == '}') {
                    st.pop();
                    continue;
                }
                if(st.top() == '[' && c == ']') {
                    st.pop();
                    continue;
                }
            }
            st.push(c);
        }
        return st.size() == 0;
    }
};