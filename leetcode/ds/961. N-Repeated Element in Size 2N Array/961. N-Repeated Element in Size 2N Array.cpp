class Solution {
    vector <int> cnt;
public:
    Solution() {
        cnt.resize(10001, 0);
    }
    // int repeatedNTimes(vector<int>& nums) {
        
    //     map <int,int> freqMap;
    //     int ans = 1;
    //     for(auto n : nums) {
    //       freqMap[n]++;
    //         if(freqMap[n] > 1) {ans = n; break;}
    //     }
   
    //     return ans;
    // }
    int repeatedNTimes(vector<int>& nums) {
        int ans;
        for(auto n : nums) {
            if(cnt[n]) {
                ans = n;
                break;
            }
            cnt[n]++;
        }
        return ans;
    }
};