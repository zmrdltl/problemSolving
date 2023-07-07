class Solution {
public:
    static bool cmp (string a, string b) {
        return a.size() < b.size();
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector <int> charMap(26,0);
        for(auto l : licensePlate) {
            if(isalpha(l))
                charMap[tolower(l) - 'a']++;
        }

        string result = string(16, 'z');

        for(string &w : words) {
            vector <int> wMap(26,0);
            for(auto c : w) wMap[c-'a']++;

            bool isComplete = true;
            for(int i = 0; i < 26; i++) {
                if(wMap[i] < charMap[i]) {
                    isComplete = false;
                    break;
                }
            }
            if(isComplete && w.size() < result.size()) result = w;
        }
        return result;
    }
};