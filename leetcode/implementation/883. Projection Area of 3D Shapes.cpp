class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            int xy = 0, yz = 0, zx = 0;
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j]) xy++;
                yz = max(yz, grid[i][j]);
                zx = max(zx, grid[j][i]);
            }
            ans += xy + yz + zx;
        }
        return ans;
    }
};