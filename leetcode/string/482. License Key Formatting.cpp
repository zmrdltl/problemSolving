class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string filteredS, ans;
        for(auto c : s) if(c != '-') filteredS += c;
        for(auto &a : filteredS) a = toupper(a);
        int firstGroupLength = filteredS.size() % k;
        ans = filteredS.substr(0, firstGroupLength);
        if(ans != "" && ans != s) ans += "-";
        for(int i = firstGroupLength; i < filteredS.size(); i+=k) {
            if(i != firstGroupLength) {
                ans += "-";
            }
            ans += filteredS.substr(i, k);
        }
        return ans;
    }
};