class Solution {
public:
    vector <string> split(string input, char delimiter){
        vector <string> result;
        stringstream ss(input);
        string tmp;
        while(getline(ss,tmp,delimiter)) result.push_back(tmp);
        return result;
    }

    bool wordPattern(string pattern, string s) {
        if(pattern == s && s.size() > 1) return false;
        vector <string> v = split(s, ' ');
        if(pattern.size() != v.size()) return false;
        map<string, char> m;
        map<char, string> m2;
        for(int i = 0; i < v.size(); i++) {
            if(m2.count(pattern[i])) continue;
            m[v[i]] = pattern[i];
            m2[pattern[i]] = v[i];
        }
        for(int i = 0; i < v.size(); i++) {
            if(m[v[i]] != pattern[i]) {
                return false;
            }
        }
        return true;
    }
};