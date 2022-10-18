class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(auto c : s) {
            if(c == '(' || c == '[' || c == '{') {
                st.push(c);
                continue;
            }
            if(st.size() && 
               ((st.top() == '(' && c == ')') || 
                (st.top() == '[' && c == ']') || 
                (st.top() == '{' && c == '}')
               )){
                st.pop();
                continue;
            }
            else {
                st.push(c);
                break;
            }
        }
        return st.size() == 0;
    }
};