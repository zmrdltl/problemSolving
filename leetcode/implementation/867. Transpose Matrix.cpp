class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> transposedMatrix(matrix[0].size(), (vector<int>(matrix.size(),0)));
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0; i < col; i++) {
            for(int j = 0; j < row; j++) {
                transposedMatrix[i][j] = matrix[j][i];
            }
        }
        return transposedMatrix;
    }
};
