class Solution {
public:
    string replaceDigits(string s) {
        char prev = s[0];
        for (int i = 1; i < s.size(); i++) {
            if('0' <= s[i] && s[i] <= '9') {
                int move = s[i] - '0';
                s[i] = prev + move;
            }
            prev = s[i];
        }
        return s;
    }
};