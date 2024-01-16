class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map <int,int> freqMap;
        for(auto a : arr) {
            freqMap[a]++;
        }
        for(auto f : freqMap){
            if(f.second * 4 > arr.size()) return f.first;
        }
        return 0;
    }
};