class Solution {
public:
    int getAvg(int r, int c, int rLimit, int cLimit, vector<vector<int>>& img) {
        int cnt = 0;
        int sum = 0;
        for(int k = r-1; k <= r + 1; k++) {
            if(k < 0 || k >= rLimit) continue;
            for(int l = c - 1; l <= c + 1; l++) {
                if(l < 0 || l >= cLimit) continue;
                cnt++;
                sum += img[k][l];
            }
        }
        return sum / cnt;
    }
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int r = img.size();
        int c = img[0].size();
        vector<vector<int>> v(r, vector<int>(c,0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int avg = getAvg(i, j, r, c, img);
                v[i][j] = avg;
            }
        }
        return v;

    }
};