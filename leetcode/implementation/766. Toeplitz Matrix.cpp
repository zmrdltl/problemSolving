class Solution {
public:
     bool isDiagonalNumAllSame(int startRow, int startCol, vector<vector<int>>& matrix) {
        int pivNum = matrix[startRow][startCol];
        int r = startRow + 1;
        int c = startCol + 1;
        while(r < matrix.size() && c < matrix[0].size()) {
            if(pivNum != matrix[r][c]) return false;
            r++;
            c++;
        }
        return true;
    }

    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int r = 0; r < matrix.size(); r++) {
            if (!isDiagonalNumAllSame(r, 0, matrix)) return false;
        }
        for (int c = 1; c < matrix[0].size(); c++) {
            if (!isDiagonalNumAllSame(0, c, matrix)) return false;
        }
        return true;
    }
};