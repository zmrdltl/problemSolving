class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int aliceTotal = 0, bobTotal = 0, diff;
        for(auto a : aliceSizes) aliceTotal += a;
        for(auto b : bobSizes) bobTotal += b;
        diff = aliceTotal - (aliceTotal + bobTotal) / 2;
        sort(bobSizes.begin(), bobSizes.end());
        for(auto a : aliceSizes) {
            int key = a - diff;
            auto idx = lower_bound(bobSizes.begin(), bobSizes.end(), key);
            if(idx == bobSizes.end()) continue;
            if(a - *idx == diff)
                return {a, *idx};
        }
        return {};
    }
};