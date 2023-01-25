class Solution {
public:
    int addDigits(int num) {
        string digit = to_string(num);
        while(digit.size() > 1) {
            int sum = 0;
            for(auto d : digit) {
                sum += d - '0';
            }
            digit = to_string(sum);
        }
        return stoi(digit);
    }
};