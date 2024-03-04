class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        for(auto a: arr1) {
            int flag = 1;
            for(auto b : arr2) {
                if (abs(b-a) <= d) {
                    flag = 0; 
                    break;
                }
            }
            cnt += flag;
        }
        return cnt;
    }
};