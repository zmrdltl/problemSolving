class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0; i < points.size() - 1; i++) {
            vector<int> curPoint = points[i];
            vector<int> nextPoint = points[i+1];
            ans += max(abs(nextPoint[0] - curPoint[0]), abs(nextPoint[1] - curPoint[1]));
        }
        return ans;
    }
};