class Solution {
public:
    vector <string> split(string input, char delimeter) {
        stringstream ss(input);
        vector <string> res;
        string tmp;
        while(getline(ss, tmp, delimeter)) {
            res.push_back(tmp);
        }
        return res;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        vector <string> s = split(sentence, ' ');
        for(int i = 0; i < s.size(); i++) {
            auto searchResult = s[i].find(searchWord);
            if (searchResult == 0 ) return i + 1;
        }
        return -1;
    }
};