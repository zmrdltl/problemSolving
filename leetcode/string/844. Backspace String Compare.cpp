class Solution {
public:
    string getFinalString(string str) {
        string madeStr;
        for(auto c : str) {
            if(c == '#') {
                if(madeStr.size()) madeStr.pop_back();
                continue;
            }
            madeStr += c;
        }
        return madeStr;
    }
    bool backspaceCompare(string s, string t) {
        string madeS = getFinalString(s);
        string madeT = getFinalString(t);
        return madeS == madeT;
    }
};