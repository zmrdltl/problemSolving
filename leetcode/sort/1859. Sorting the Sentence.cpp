class Solution {
public:
    vector <string> split(string input, char delimeter) {
        stringstream ss(input);
        string tmp;
        vector <string> res;
        while (getline(ss, tmp, delimeter)) {
            res.push_back(tmp);
        }
        return res;
    }

    vector<string> getFilteredSentence(vector<string> splitedSentence) {
        for(auto &word : splitedSentence) {
            string wordForSwap = "";
            for(auto w : word) {
                if(isdigit(w)) continue;
                wordForSwap += w;
            }
            word = wordForSwap;
        }
        return splitedSentence;
    }

    string sortSentence(string s) {
        vector <string> splitedSentence = split(s, ' ');
        string ans;
        int sz = splitedSentence.size();
        for(int pos = 1; pos <= sz; pos++) {
            string sortedWord;
            for (auto w : splitedSentence) {
                int wSize = w.size();
                if(w[wSize-1] - '0' == pos) {
                    sortedWord = w.substr(0, wSize - 1);
                    break;
                }
            }
            ans += sortedWord;
            if (pos != sz) ans += ' ';
        }
        return ans;
    }
};