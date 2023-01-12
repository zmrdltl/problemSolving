class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector <string> ans;
        for(int curIdx = 0; curIdx < nums.size(); curIdx++) {
            int piv = curIdx;
            long long cnt = nums[curIdx];
            for(int nextIdx = curIdx; nextIdx < nums.size(); nextIdx++) {
                if(nums[nextIdx] != cnt) break;
                cnt++;
                piv = nextIdx;
            }
            if(curIdx != piv) {
                ans.push_back(to_string(nums[curIdx]) + "->" + to_string(nums[piv]));
            }
            else {
                ans.push_back(to_string(nums[curIdx]));
            }
            curIdx = piv;
        }
        return ans;
    }
};