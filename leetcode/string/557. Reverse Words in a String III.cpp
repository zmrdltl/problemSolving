class Solution {
public:
    vector <string> split(string input, char delimeter){
        vector <string> res;
        stringstream ss(input);
        string token;
        while(getline(ss,token,delimeter)){
            res.push_back(token);
        }
        return res;
    }
    
    string reverseWords(string s) {
        vector <string> splitedString = split(s, ' ');
        string ans;
        for(auto sp : splitedString) {
            reverse(sp.begin(), sp.end());
            ans += sp + " ";
        }

        return ans.substr(0, ans.size() - 1);
    }
};