class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for (int piv = left; piv <= right; piv++) {
            bool cover = false;
            for(auto r : ranges) {
                if (r[0] <= piv && piv <= r[1]) {
                    cover = true;
                    break;
                }
            }
            if(!cover) return false;
        }
        return true;
    }
};