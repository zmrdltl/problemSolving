class Solution {
public:
    vector <string> split(string input, char delimeter) {
        vector <string> res;
        stringstream ss(input);
        string tmp;
        while(getline(ss,tmp,delimeter)) {
            res.push_back(tmp);
        }
        return res;
    }
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c =='o' || c=='u';
    }

    string toGoatLatin(string sentence) {
        vector <string> words = split(sentence, ' ');
        string ans;
        for(int i = 0; i < words.size(); i++) {
            string &word = words[i];
            if(isVowel(tolower(word[0]))) {
                word += "ma";
            } else {
                word = word.substr(1) + word[0] + "ma";
            }
            string a(i+1,'a'); 
            word += a;
        }
        for(auto w : words) {
            ans += w + " ";
        }
        ans.pop_back();
        return ans;
    }
};