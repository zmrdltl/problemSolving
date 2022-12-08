class Solution {
public:
    string convertToTitle(int columnNumber) {
        vector <int> v;
        while(columnNumber) {
            v.push_back(--columnNumber % 26);
            columnNumber /= 26;
        }
        reverse(v.begin(), v.end());
        string ans;
        for(auto e : v) ans += e + 'A';
        return ans;
    }
};