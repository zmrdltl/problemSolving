class Solution {
public:
    vector <string> split(string input, char delimiter) {
        vector <string> res;
        stringstream ss(input);
        string tmp;
        while(getline(ss,tmp,delimiter)) {
            if (tmp == "") continue;
            res.push_back(tmp);
        }
        return res;
    }

    int countSegments(string s) {
        return split(s, ' ').size();
    }
};