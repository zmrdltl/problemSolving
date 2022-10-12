class Solution {
    map <char, int> symbolMap;
public:
    void initMap() {
        symbolMap['I'] = 1;
        symbolMap['V'] = 5;
        symbolMap['X'] = 10;
        symbolMap['L'] = 50;
        symbolMap['C'] = 100;
        symbolMap['D'] = 500;
        symbolMap['M'] = 1000;
    }
    int romanToInt(string s) {
        initMap();
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(i != s.size() - 1) {
                if(s[i] == 'I') {
                    if(s[i+1] == 'V') { ans += 4; i++; continue;}
                    else if(s[i+1] == 'X') { ans += 9; i++; continue;}
                }
                if(s[i] == 'X') {
                    if(s[i+1] == 'L') { ans += 40; i++; continue;}
                    else if(s[i+1] == 'C') { ans += 90; i++; continue;}
                }
                if(s[i] == 'C') {
                    if(s[i+1] == 'D') { ans += 400; i++; continue;}
                    else if(s[i+1] == 'M') { ans += 900; i++; continue;}
                }
            }
            ans += symbolMap[s[i]];
        }
        return ans;
    }
};