class Solution {
public:
    int dr[4] = {0,0,1,-1};
    int dc[4] = {1,-1,0,0};
    int surfaceArea(vector<vector<int>>& grid) {
        int ans = 0;
        int height = grid.size();
        int width = grid[0].size();
        for(int r = 0; r < height; r++) {
            for(int c = 0; c < width; c++) {
                int cnt = 0;
                for(int dir = 0; dir < 4; dir++) {
                    int nr = r + dr[dir];
                    int nc = c + dc[dir];
                    if(0 > nr || nr >= height || 0 > nc || nc >= width) {
                        ans += grid[r][c]; continue; //가장자리면
                    }
                    if(grid[r][c] > grid[nr][nc])
                        ans += grid[r][c] - grid[nr][nc]; //옆면
                }
                if(grid[r][c]) ans += 2; //윗면 아랫면
            }
        }
        return ans;
    }
};