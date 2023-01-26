class Solution {
public:
    map <int,int> check;
    bool getUgly(long long current, long long target) {
        if(check[current]) return false;
        check[current] = 1;
        if(current > target) return false;
        if(current == target) return true;
        return max({getUgly(current*2, target), getUgly(current*3, target), getUgly(current*5, target)});
    }

    bool isUgly(int n) {
        if(n <= 0) return false;
        return getUgly(1, n);
    }
};