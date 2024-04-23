class Solution {
public:
    bool needErase(char c1, char c2) { 
        //97 - 65
        return abs(c1 - c2) == 32;
    }
    string makeGood(string s) {
        stack <char> st;
        cout << s << '\n';
        for(int i = 0; i < s.size(); i++) {
            if (st.size() && needErase(st.top(), s[i])) st.pop();
            else st.push(s[i]);
        }
        string ans;
        while(st.size()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};