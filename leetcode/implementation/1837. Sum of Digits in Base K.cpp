class Solution {
public:
    int sumBase(int n, int k) {
        string bin = "";
        while (n) {
            bin += to_string(n % k);
            n /= k;
        }
        int sum = 0;
        for(auto b : bin) {
            sum += b - '0';
        }
        return sum;
    }
};