class Solution {
public:
    //U, D, L, R
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    bool judgeCircle(string moves) {
        int r = 0, c = 0;
        for(auto m : moves) {
            if(m == 'U') r += dr[0], c += dc[0];
            if(m == 'D') r += dr[1], c += dc[1];
            if(m == 'L') r += dr[2], c += dc[2];
            if(m == 'R') r += dr[3], c += dc[3];
        }
        return !r && !c;
    }
};