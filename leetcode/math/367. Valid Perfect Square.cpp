class Solution {
public:
    bool isPerfectSquare(int num) {
        long long cnt = 0;
        for(int i = 1; cnt <= num; i += 2) {
            cnt += i;
            if(cnt == num) return true;
        }
        return false;
    }
};