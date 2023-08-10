class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> consecutiveList;
        int cnt = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i-1]) {
                cnt++;
            } else {
                consecutiveList.push_back(cnt);
                cnt = 1;
            }
        }
        consecutiveList.push_back(cnt);

        int ans = 0;
        for(int i = 1; i < consecutiveList.size(); i++) {
            ans += min (consecutiveList[i-1], consecutiveList[i]);
        }
        return ans;
    }
};