class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int maxFreq = 0;
        int length = 0x3f3f3f3f;
        map <int ,vector<int>> idxOfNumsMap;

        for(int i = 0; i < nums.size(); i++) {
            idxOfNumsMap[nums[i]].push_back(i);
        }
        
        for(auto im : idxOfNumsMap) {
            int curFreq = im.second.size();
            maxFreq = max(maxFreq, curFreq);
        }

        for(auto im : idxOfNumsMap) {
            int curFreq = im.second.size();
            if(maxFreq == curFreq) {
                vector <int> idxs = idxOfNumsMap[im.first];
                length = min(length, idxs[idxs.size() - 1] - idxs[0] + 1);
            }
        }
        return length;
    }
};