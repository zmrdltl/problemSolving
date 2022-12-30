class Solution {
public:
    bool isHappy(int n) {
        string num = to_string(n);
        map <int,int> dict;
        while(1) {
            int sum = 0;
            for(auto n : num) {
                sum += pow(n - '0', 2);
            }
            if(dict[sum] || num == "1") {
                break;
            }
            num = to_string(sum);
            dict[sum] = 1;
        }
        return num == "1";
    }
};