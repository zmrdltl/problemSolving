// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         vector <int> count(100000,0);
//         int ans = 0;
//         for(auto &n : nums) {
//             count[n + 30000]++;
//         }
//         for(int i = 0; i < 100000; i++) {
//             if(count[i] == 1) {
//                 ans = i - 30000;
//                 break;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map <int, int> countMap;
        int ans = 0;
        for(auto &n : nums) {
            countMap[n]++;
        }
        for(auto el : countMap) {
            if(el.second == 1) {
                ans = el.first;
                break;
            }
        }
        return ans;
    }
};