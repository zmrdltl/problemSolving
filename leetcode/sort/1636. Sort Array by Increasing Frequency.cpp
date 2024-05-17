class Solution {
    static map<int, int> freqMap;
public:
    static bool cmp(int a, int b) {
        if (freqMap[a] == freqMap[b]) {
            return a > b;
        }
        return freqMap[a] < freqMap[b];
    }
    vector<int> frequencySort(vector<int>& nums) {
        freqMap.clear();
        for (auto n : nums) {
            freqMap[n]++;
        }
        sort(nums.begin(), nums.end(), cmp);
        return nums;
    }
};

map<int, int> Solution::freqMap;