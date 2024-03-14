class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int value = 0;
        int acc = 0;
        for(auto n : nums) {
            acc += n;
            if (acc < 1) {
                value += 1 - acc;
                acc = 1;
            }
        }
        if(!value) value = 1;
        return value;
    }
};
