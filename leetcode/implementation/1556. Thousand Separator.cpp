class Solution {
public:
    string thousandSeparator(int n) {
        string str = to_string(n);
        string ans;
        stack <char> st;
        int cnt = 0;
        for(int i = str.size() - 1; i >= 0; i--) {
            char c = str[i];
            st.push(c);
            cnt++;
            if(cnt % 3 == 0 && i != 0) {
                st.push('.');
            }
        }
        while(st.size()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};