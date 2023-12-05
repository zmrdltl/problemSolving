class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map <int ,int> freqMap, uniqueMap;

        for(auto a : arr) {
            freqMap[a]++;
        }
        
        for(auto el : freqMap) {
            if(uniqueMap[el.second]) return false;
            uniqueMap[el.second] = 1;
        }

        return true;
    }
};