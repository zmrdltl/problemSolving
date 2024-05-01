class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int ans = 0;
        
        vector<int> rowCount(row,0);
        vector<int> colCount(col,0);

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                rowCount[i] += mat[i][j];
                colCount[j] += mat[i][j];
            }
        }
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(mat[i][j] && rowCount[i] == 1 && colCount[j] == 1) ans++;
            }
        }

        return ans;
    }
};