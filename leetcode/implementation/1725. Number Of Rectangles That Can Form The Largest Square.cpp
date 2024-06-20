class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        vector <int> lengths(rectangles.size(), 0);
        for(int i = 0; i < rectangles.size(); i++) {
            int length = rectangles[i][0];
            int width = rectangles[i][1];
            lengths[i] = min(length, width);
        }
        int largest = 0, ans = 0;
        for(auto l : lengths) {
            largest = max(l, largest);
        }
        for(auto l : lengths) {
            if(largest == l) ans++;
        }
        return ans;
    }
};