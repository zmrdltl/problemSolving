class Solution {
public:
    bool hasNoZero(int num) {
      while(num > 0) {
        if (num % 10 == 0) return false;
        num /= 10;
      }
      return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i <= n/2; i++) {
            if(hasNoZero(i) && hasNoZero(n-i)) return {i, n-i};
        }
        return {};
    }
};