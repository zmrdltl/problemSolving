#define ll long long
class Solution {
public:
    string hexa = "0123456789abcdef"; 
    string toHex(int num) {
        ll n = num;
        string ans;
        if(!n) return "0";
        if(n < 0) {
            n = (1ull << 32) + n;
        }
        while(n) {
            ans += hexa[n % 16];
            n /= 16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};