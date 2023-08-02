class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveBill = 0;
        int tenBill = 0;
        int twentyBill = 0;
        for(auto b : bills) {
            if (b == 5) fiveBill++;
            if (b == 10) {
                if(fiveBill < 1) return false;
                fiveBill--;
                tenBill++;
            }
            if (b == 20) {
                if(fiveBill >= 1 && tenBill >= 1) {
                    fiveBill -= 1;
                    tenBill -= 1;
                } else if (fiveBill >= 3) {
                    fiveBill -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};