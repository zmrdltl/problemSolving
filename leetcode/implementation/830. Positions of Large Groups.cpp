class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int cnt = 0;
        int startIdx = 0, endIdx = 0;
        for(int i = 0; i < s.size()-1; i++) {
            if(s[i] != s[i+1]) {
                if(endIdx - startIdx >= 2) {
                    ans.push_back({startIdx, endIdx});
                }
                startIdx = i+1, endIdx = i+1;
            } else {
                endIdx++;
            }
        }
        if(endIdx - startIdx >= 2) {
            ans.push_back({startIdx, endIdx});
        }
        return ans;
    }
};