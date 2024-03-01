class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector <int> luckies;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                int minRowNum = matrix[i][j];
                int maxColNum = 0;
                for(int l = 0; l < c; l++) {
                    minRowNum = min(minRowNum, matrix[i][l]);
                }
                for(int k = 0; k < r; k++) {
                    maxColNum = max(maxColNum, matrix[k][j]);
                }
                if(minRowNum == maxColNum) {
                    luckies.push_back(minRowNum);
                }
             }
        }
        return luckies;
    }
};