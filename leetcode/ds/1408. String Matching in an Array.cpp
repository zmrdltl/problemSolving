class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set <string> s;
        vector <string> ans;
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words.size(); j++) {
                if(i == j) continue;
                if(words[i].find(words[j]) != string::npos) {
                    s.insert(words[j]);
                }
            }
        }
        
        for(auto c : s) {
            ans.push_back(c);
        }
        
        return ans;
    }
};