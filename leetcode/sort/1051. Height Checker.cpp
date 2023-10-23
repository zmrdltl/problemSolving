class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector <int> sorted = heights;
        sort(sorted.begin(), sorted.end());
        int diff = 0;
        for(int i = 0; i < heights.size(); i++) {
            if(heights[i] != sorted[i]) diff++;
        }
        return diff;
    }
};