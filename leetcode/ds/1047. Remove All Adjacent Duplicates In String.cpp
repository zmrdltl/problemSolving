class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        stack <char> st;
        for(auto c : s) {
            if(st.size() && st.top() == c) {
                while(st.size() && st.top() == c) {
                    st.pop();
                }
                continue;
            }
            st.push(c);
        }
        while(st.size()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};