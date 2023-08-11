class Solution {
public:
    vector <string> split(string input, char delimiter){
        vector <string> result;
        stringstream ss(input);
        string tmp;

        while(getline(ss,tmp,delimiter)) result.push_back(tmp);
        return result;
    }

    vector<string> uncommonFromSentences(string s1, string s2) {
        vector <string> sVec = split(s1, ' ');
        vector <string> s2Vec = split(s2, ' ');
        vector <string> ans;

        map <string, int> m;
        
        for(auto s : sVec) {
            m[s]++;
        }

        for(auto s : s2Vec) {
            m[s]++;
        }

        for(auto el : m) {
            if(el.second == 1) {
                ans.push_back(el.first);
            }
        }

        return ans;
    }
};
