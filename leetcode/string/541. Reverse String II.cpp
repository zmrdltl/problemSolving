class Solution {
public:
    string reverseStr(string s, int k) {
        int sSize = s.size();
        for(int i = 0; i < sSize; i += 2*k) {
            int len = min(k, sSize - i);
            reverse(s.begin() + i, s.begin() + len + i);
        }
        return s;
    }
};