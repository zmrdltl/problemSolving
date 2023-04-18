class Solution {
public:
    bool checkRecord(string s) {
        int aCnt = 0, lCnt = 0;
        for(auto c : s) {
            if(aCnt == 2 || lCnt == 3) break;
            if(c == 'A') aCnt++;
            if(c == 'L') lCnt++;
            else {
                lCnt = 0;
            }
        }
        return aCnt < 2 && lCnt < 3;
    }
};