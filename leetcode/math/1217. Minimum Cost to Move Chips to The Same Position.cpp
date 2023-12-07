class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int oddChips = 0, evenChips = 0;
        for(auto p : position) {
            if(p % 2) oddChips++;
            else evenChips++;
        }
        if(!oddChips || !evenChips) return 0;
        return min(oddChips, evenChips);
    }
};