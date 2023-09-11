class Solution {
public:
    vector<int> diStringMatch(string s) {
        int sz = s.size();
        int l = 0;
        int r = sz;
        vector <int> ans;
        for(int i = 0; i < sz; i++) {
            if(s[i] == 'I') {
                ans.push_back(l++);
            }
            if(s[i] == 'D') {
                ans.push_back(r--);
            }
        }
        ans.push_back(l);
        return ans;
    }
};