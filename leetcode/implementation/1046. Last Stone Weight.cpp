class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() >= 2) {
            sort(stones.rbegin(), stones.rend());

            if (stones[0] >= stones[1]) {
                stones[0] -= stones[1];
                stones[1] = 0;
            }
            stones.erase(remove(stones.begin(), stones.end(), 0), stones.end());
        }
        
        if(stones.empty()) return 0;
        return stones[0];
    }
};
