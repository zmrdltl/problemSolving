class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> shiftedGrid = grid;
        int m = grid.size();
        int n = grid[0].size();
        while(k--) {
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(j+1 < n) shiftedGrid[i][j+1] = grid[i][j];
                    if(i+1 < m) shiftedGrid[i+1][0] = grid[i][n-1];
                }
            }
            shiftedGrid[0][0] = grid[m-1][n-1];
            grid = shiftedGrid;
        }
        return shiftedGrid;
    }
};