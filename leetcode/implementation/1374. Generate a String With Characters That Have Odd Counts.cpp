class Solution {
public:
    string generateTheString(int n) {
        // 1 a
        // 2 a b
        // 3 a a a
        // 4 a a a b
        // 5 a a a a a
        string ans;
        if (n % 2) {
            for(int i = 0; i < n; i++) {
                ans += 'a';
            }
        } else {
            for(int i = 0; i < n - 1; i++) {
                ans += 'a';
            }
            ans += 'b';
        }
        return ans;
    }
};