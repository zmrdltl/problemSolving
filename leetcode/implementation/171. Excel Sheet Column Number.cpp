class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for(int i = 0; i < columnTitle.size(); i++) {
            ans += (columnTitle[columnTitle.size() - 1 -i] - 'A' + 1) * pow(26,i);
        }
        return ans;
    }
};