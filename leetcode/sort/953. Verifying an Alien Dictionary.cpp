map<char, int> scoreMap;

bool cmp (string &a, string &b) {
    int minSize = min(a.size(), b.size());
    for(int i = 0; i < minSize; i++) {
        if(scoreMap[a[i]] == scoreMap[b[i]]) continue;
        return scoreMap[a[i]] > scoreMap[b[i]];
    }
    string aa = a.substr(minSize);
    string bb = b.substr(minSize);
    if(aa.size() == bb.size()){
        return scoreMap[aa[0]] > scoreMap[bb[0]];
    }
    return aa.size() < bb.size();
}

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<string> sortedWords = words;
       
        for(int i = order.size() - 1, score = 1; i >= 0; i--, score++) {
            scoreMap[order[i]] = score;
        }
        sort(sortedWords.begin(), sortedWords.end(), cmp);
        for(int i = 0; i < sortedWords.size(); i++) {
            if(sortedWords[i] != words[i]) return false;
        }
        return true;
    }
};