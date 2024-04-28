class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sideLength = mat.size();
        int sum = 0;
        for(int i = 0; i < sideLength; i++) {
            if (sideLength % 2 && i == sideLength / 2) continue;
            sum += mat[i][i];
        }
        for(int i = 0; i < sideLength; i++) {
            sum += mat[sideLength - i - 1][i];
        }
        return sum;
    }
};