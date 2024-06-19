class Solution {
public:
    int totalMoney(int n) {
        vector <int> depositAmountPerDay(n+1, 0);
        for(int i = 1; i <= n; i++) {
            if(i > 7 && i % 7 == 1) {
                depositAmountPerDay[i] += depositAmountPerDay[i-7] + 1;
            } else {
                depositAmountPerDay[i] += depositAmountPerDay[i-1] + 1;
            }
        }
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += depositAmountPerDay[i];
        }
        return sum;
    }
};