class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector <int> ans(code.size());
        for(int i = 0; i < code.size(); i++) {
            int sum = 0;
            for (int next = 0; next < abs(k); next++) {
                if(k > 0) {
                    sum += code[(i+1+next) % code.size()];
                } else if (k < 0) {
                    sum += code[(i-1 - next + code.size()) % code.size()];
                }
            }
            ans[i] = sum;
        }
        return ans;
    }
};