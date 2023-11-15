class Solution {
    vector <int> charAlphas;
public:
    bool canBeFormed(vector <int> wordAlphas, vector <int> charAlphas) {
        for(int i = 0; i < 26; i++) {
            if(wordAlphas[i] > charAlphas[i]) {
                return false;
            }
        }
        return true;
    }
    void countAlphas(string chars) {
        charAlphas.resize(26,0);
        for(auto c : chars) {
            charAlphas[c - 'a']++;
        }
    }
    int countCharacters(vector<string>& words, string chars) {
        countAlphas(chars);
        int ans = 0;
        for(auto w : words) {
            vector <int> wordAlphas(26,0);
            for(auto c : w) {
                wordAlphas[c - 'a']++;
            }
            if(canBeFormed(wordAlphas, charAlphas)) ans += w.size();
        }
        return ans;
    }
};