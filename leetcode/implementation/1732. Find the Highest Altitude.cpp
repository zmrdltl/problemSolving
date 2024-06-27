class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0;
        int curAltitude = 0;
        for(auto g : gain) {
            curAltitude += g;
            maxAltitude = max(maxAltitude, curAltitude);
        }
        return maxAltitude;
    }
};