class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set <int> s;
        for(auto n : nums) {
            s.insert(n);
        }
        int cnt = 0;
        for(auto e : s){
            nums[cnt] = e;
            cnt++;
        }
        return s.size();
    }
};