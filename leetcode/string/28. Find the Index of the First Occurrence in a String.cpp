class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = haystack.find(needle);
        return ans == string::npos ? -1 : ans;
    }
};