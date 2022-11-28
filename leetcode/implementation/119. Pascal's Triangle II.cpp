class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector <vector<int>> pascal;
        for(int i = 0; i <= rowIndex; i++) {
            vector <int> v;
            for(int j = 0; j <= i; j++) {
                if(i == j || j == 0) v.push_back(1);
                else v.push_back(pascal[i-1][j-1] + pascal[i-1][j]);
            }
            pascal.push_back(v);
        }
        return pascal[rowIndex];
    }
};