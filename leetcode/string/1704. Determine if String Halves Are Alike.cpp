class Solution {
public:
    int countVowel(string s) {
        int cnt = 0;
        for(auto el : s) {
            char c = tolower(el);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++;
        }
        return cnt;
    }

    bool halvesAreAlike(string s) {
        int halfSize = s.size() / 2;
        string a = s.substr(0, halfSize);
        string b = s.substr(halfSize);
        return countVowel(a) == countVowel(b) && a.size() == b.size();
    }
};