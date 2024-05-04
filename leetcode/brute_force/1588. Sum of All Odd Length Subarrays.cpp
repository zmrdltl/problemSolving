class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        for (int len = 1; len <= arr.size(); len+=2) {
            for (int start = 0; start <= arr.size() - len; start++) {
                int sum = 0;
                for (int i = start; i < start + len; i++) {
                    sum += arr[i];
                }
                ans += sum;
            }
        }
        return ans;
    }
};