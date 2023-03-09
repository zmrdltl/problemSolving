class Solution {
public:
    int longestPalindrome(string s) {
        int odds = 0;
        map <char, int> m;
        for(auto c : s) {
            m[c]++;
        }
        for(auto el : m) {
            if(el.second & 1) {
                odds++;
            }
        }
        return s.size() - odds + (odds > 0);
    }
};