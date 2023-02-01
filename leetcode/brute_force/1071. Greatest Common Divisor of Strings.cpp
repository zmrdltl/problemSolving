class Solution {
public:
    bool isDivisorString(string str, string piv){
        for(int i = 0; i < str.size(); i += piv.size()) {
            string sub = str.substr(i, piv.size());
            if(sub != piv) return false;
        }
        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        string ans = "";
        for(int i = 0; i < str2.size(); i++) {
            string subStr2 = str2.substr(i);
            int isDivisor = 1;
            isDivisor = min(isDivisorString(str1, subStr2), isDivisorString(str2, subStr2));
            if(isDivisor && ans.size() < subStr2.size())
                ans = subStr2;
        }
        return ans;
    }
};