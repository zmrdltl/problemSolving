class Solution {
public:
    bool checkOnesSegment(string s) {
        int segment = 0;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                while(i + 1 < s.size() && s[i] == s[i+1]) i++;
                segment++;
            }
        }
        return segment <= 1;
    }
};