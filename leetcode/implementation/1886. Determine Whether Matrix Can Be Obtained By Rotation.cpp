class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>> &mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> tmp(c, vector<int>(r));
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                tmp[c-j-1][i] = mat[i][j];
            }
        }
        return tmp;
    }
    bool isSame(vector<vector<int>> a, vector<vector<int>> b) {
        for(int i = 0; i < a.size(); i++) {
            for(int j = 0; j < a[0].size(); j++) {
                if(a[i][j] != b[i][j]) return false;
            }
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0; i < 4; i++) {
            if(isSame(mat, target)) return true;
            mat = rotate(mat);
        }
        return false;
    }
};