class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector <int> ans;
        stack <int> odd, even;
        for(auto n : nums) {
            if(n%2) odd.push(n);
            else even.push(n);
        }
        for(int i = 0; i < nums.size() / 2; i++) {
            ans.push_back(even.top());
            even.pop();
            ans.push_back(odd.top());
            odd.pop();
        }
        return ans;
    }
};