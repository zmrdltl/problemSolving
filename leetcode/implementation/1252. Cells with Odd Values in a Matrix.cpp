class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector <vector<int>> matrix(m,vector<int>(n,0));
        int oddCnt = 0;
        for(auto indice : indices) {
            int row = indice[0];
            int col = indice[1];
            for(int i = 0; i < n; i++) matrix[row][i]++;
            for(int i = 0; i < m; i++) matrix[i][col]++;
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] % 2) oddCnt++;
            }   
        }
        return oddCnt;
    }
};