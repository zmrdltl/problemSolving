class Solution {
public:
    string sortString(string s) {
        string res = "";
        int freq[26] = {0};

        for(auto c : s) {
            freq[c - 'a']++;
        }
        
        while(s.size() > res.size()) {
            for(int i = 0; i < 26; i++) {
                if(freq[i]) {
                    res += i + 'a';
                    freq[i]--;
                }
            }

            for(int i = 25; i >= 0; i--) {
                if(freq[i]) {
                    res += i + 'a';
                    freq[i]--;
                }
            }
        }
        
        return res;
    }
};