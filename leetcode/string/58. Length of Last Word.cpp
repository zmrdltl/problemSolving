#include <bits/stdc++.h>
class Solution {
public:
    vector <string> split(string input, char delimiter){
        vector <string> result;
        stringstream ss(input);
        string tmp;
        while(getline(ss,tmp,delimiter)) result.push_back(tmp);
        return result;
    }

    int lengthOfLastWord(string s) {
        int length = 0;
        vector <string> v = split(s, ' ');
        for(auto e : v) {
            if(e == "") continue;
            length = e.size();
        }
        return length;
    }
};
