class Solution {
public:
    int countBit(string bin, char piv) {
        int bits = 0;
        for(auto b : bin) {
            if(b == piv) {
                bits++;
            }
        }
        return bits;
    }

    int maxScore(string s) {
        int ms = 0;
        for(int piv = 1; piv < s.size(); piv++) {
            string a = s.substr(0, piv);
            string b = s.substr(piv);
            ms = max(ms, countBit(a, '0') + countBit(b, '1'));
        }
        return ms;
    }
};