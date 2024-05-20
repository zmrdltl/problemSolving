class Solution {
public:
    static bool cmp (vector <int> a, vector <int> b) {
        if(a[0]==b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int maxWidth = 0;
        for(int i = 1; i < points.size(); i++) {
            maxWidth = max(maxWidth, points[i][0] - points[i-1][0]);
        }
        return maxWidth;
    }
};