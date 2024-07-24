class Solution {
public:
    string longestNiceSubstring(string s) {
        string substring;
        for(int i = 0; i < s.size(); i++) {
            for(int j = 1; j <= s.size(); j++) {
                string sb = s.substr(i,j);
                bool isValid = true;
                for(int k = 0; k < sb.size(); k++) {
                    char lower = tolower(sb[k]);
                    char upper = toupper(sb[k]);
                    if (sb.find(lower) == string::npos || sb.find(upper) == string::npos) {
                        isValid = false;
                        break;
                    }
                }
                if(isValid) {
                    if (substring.size() < sb.size()) {
                        substring = sb;
                    }
                }
            }
        }
        return substring;
    }
};