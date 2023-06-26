class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector <int> ans;
        for(int i = left; i <= right; i++) {
            string numString = to_string(i);
            bool isDividingNum = true;
            for(auto n : numString) {
                if(n == '0' || i % (n - '0')) {
                    isDividingNum = false;
                    break;
                }
            }
            if(isDividingNum)
                ans.push_back(i);
        }
        return ans;
    }
};