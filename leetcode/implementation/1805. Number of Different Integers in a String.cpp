class Solution {
public:
    string trimWord(string word) {
        string trimmed;
        int piv = 0;
        for(int i = 0; i < word.size(); i++) {
            if (word[i] != '0') break;
            piv++;
        }
        return word.substr(piv);
    }
    
    int numDifferentIntegers(string word) {
        int sz = word.size();
        string intWord = "";
        map <string, int> intFrequencyMap;

        for(int i = 0; i < sz; i++) {
            while (i < sz && isdigit(word[i])) {
                intWord += word[i];
                i++;
            }
            if (intWord.size()) {
                intFrequencyMap[trimWord(intWord)]++;
                intWord = "";
            }
        }
        return intFrequencyMap.size();
    }
};