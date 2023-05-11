class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.size() == 0) return m * n;
        int maxX = 0x3f3f3f3f, maxY = 0x3f3f3f3f;
        for(auto o : ops) {
            int x = o[0];
            int y = o[1];
            maxX = min(maxX, x);
            maxY = min(maxY, y);
        }
        return maxX * maxY;
    }
};