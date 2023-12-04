class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int minDiff = 0x3f3f3f3f;
        for(int i = 0; i < arr.size() - 1; i++) {
            minDiff = min(minDiff, arr[i+1] - arr[i]);
        }
        for(int i = 0; i < arr.size() - 1; i++) {
            if(arr[i+1] - arr[i] == minDiff) {
                ans.push_back({arr[i], arr[i+1]});
            }
        }
        return ans;
    }
};