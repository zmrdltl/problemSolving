class Solution {
public:
    int maxPower(string s) {
        int maxPower = 1;
        int curPower = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i-1]) {
                curPower++;
                maxPower = max(curPower,maxPower);
            } else {
                curPower = 1;
            }
        }
        return maxPower;
    }
};