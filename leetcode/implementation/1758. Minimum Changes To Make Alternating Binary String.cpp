class Solution {
public:
    string getFilpedPattern(int length, int mode) {
        int bit = mode;
        string pattern ="";
        while(length--) {
            pattern += to_string(bit);
            bit = !bit;
        }
        return pattern;
    }

    int minOperations(string s) {
        int pattern1Altered = 0, pattern2Altered = 0;
        int length = s.size();
        string pattern1 = getFilpedPattern(length, 0);
        string pattern2 = getFilpedPattern(length, 1);
        cout << pattern1 << ' ' << pattern2 << '\n';
        for(int i = 0; i < length; i++) {
            if(pattern1[i] != s[i]) pattern1Altered++;
            if(pattern2[i] != s[i]) pattern2Altered++;
        }
        return min(pattern1Altered, pattern2Altered);
    }
};