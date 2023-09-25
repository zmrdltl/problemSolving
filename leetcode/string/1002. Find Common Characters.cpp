class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector <int> minFreq(26, INT_MAX);
        vector <string> ans;

        for(auto w : words) {
            vector <int> freq(26,0);
            for(auto c : w) freq[c - 'a']++;
            for(int i = 0; i < 26; i++) minFreq[i] = min(minFreq[i], freq[i]);
        }

        for(int i = 0; i < 26; i++) {
            if(!minFreq[i]) continue;
            for(int j = 0; j < minFreq[i]; j++)
                ans.push_back(string(1, i + 'a'));
        }
        
        return ans;
    }
};