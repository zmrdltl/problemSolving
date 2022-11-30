class Solution {
public:
    string getTrimedString(string s){
        string tmp;
        for(auto c : s) {
            if('a' <= c && c <= 'z' || '0' <= c && c <= '9') tmp += c;
            else if('A' <= c && c <= 'Z') tmp += c - 'A' + 'a';
        }
        return tmp;
    }
    bool isPalindrome(string s) {
        s = getTrimedString(s);
        int sz = s.size();
        for(int i = 0; i < sz / 2; i++) {
            if(s[i] != s[sz - 1 - i]) return false;
        }
        return true;
    }
};