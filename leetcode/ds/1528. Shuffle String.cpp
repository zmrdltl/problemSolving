class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        map<int, char> m;
        string ans;

        for(int i = 0; i <indices.size(); i++) {
            m[indices[i]] = s[i]; 
        }
        for(auto el : m) {
            ans += el.second;
        }

        return ans;
    }
};