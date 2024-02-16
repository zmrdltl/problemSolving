class Solution {
public:
    static int bits(int n) {
        int cnt = 0;
        while(n) {
            cnt += n & 1;
            n >>= 1;
        }
        return cnt;
    }

    static bool cmp (int &a, int &b) {
        int aBits = bits(a);
        int bBits = bits(b);
        if(aBits == bBits) return a < b;
        return aBits < bBits;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};