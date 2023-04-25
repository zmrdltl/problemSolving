class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(mat.size() * mat[0].size() != r*c) return mat;
        vector <int> nums;
        vector<vector<int>> ans(r, vector<int>(c));
        for(auto i : mat) {
            for(auto j : i) {
                nums.push_back(j);
            }
        }
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                ans[i][j] = nums[i*c+j];
            }
        }
        return ans;
    }
};