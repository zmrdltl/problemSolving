class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0; i < s.size() / 2; i++) {
            if(s[i] != s[s.size()-1-i]) return false;
        }
        return true;
    }

    int removePalindromeSub(string s) {
        if(s.empty()) return 0;
        if(isPalindrome(s)) return 1;
        return 2;
    }
};