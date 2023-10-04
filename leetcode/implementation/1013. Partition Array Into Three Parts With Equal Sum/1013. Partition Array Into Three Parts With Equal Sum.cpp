class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        int pivSum = 0;
        for(auto a : arr) sum += a;
        if(sum % 3) return false;
        pivSum = sum / 3;
        sum = 0;
        vector <int> pivIdx;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if(sum == pivSum) {
                pivIdx.push_back(i);
                sum = 0;
            }
        }
        return pivIdx.size() >= 3;
    }
};