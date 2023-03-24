class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};
        int perimeter = 0;
        int rLength = grid.size();
        int cLength = grid[0].size();
        for(int i = 0; i < rLength; i++) {
            for(int j = 0; j < cLength; j++) {
                if(!grid[i][j]) continue;
                int near = 0;
                for(int dir = 0; dir < 4; dir++) {
                    int nr = i + dr[dir];
                    int nc = j + dc[dir];
                    if(0 > nr || nr >= rLength || 0 > nc || nc >= cLength) continue;
                    if(grid[nr][nc]) {
                        near++;
                    }
                }
                perimeter += 4 - near;
            }
        }
        return perimeter;
    }
};