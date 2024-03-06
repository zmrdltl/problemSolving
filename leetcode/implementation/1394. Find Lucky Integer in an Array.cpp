class Solution {
public:
    int findLucky(vector<int>& arr) {
        map <int, int> freqMap;
        for(auto a : arr) {
            freqMap[a]++;
        }
        int maxLuckyNum = -1;
        for(auto f : freqMap) {
            int num = f.first;
            int numFreq = f.second;
            if(num != numFreq) continue;
            maxLuckyNum = max(maxLuckyNum, num);
        }
        return maxLuckyNum;
    }
};