class Solution {
public:
    static bool cmp(string &a, string &b){
        if(a.size() == b.size()) return a < b;
        return a.size() < b.size();
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end(), cmp);
        string ans;
        
        for(int j = 0; j < strs[0].size(); j++){
            int isValid = 0;
            int i = 1;

            for(; i < strs.size(); i++){
                if(strs[0][j] != strs[i][j]) {
                    isValid = 1; 
                    break;
                }
            }
            
            if(!isValid) {
                ans += strs[0][j];
            }
            
            else {
                break;
            }
        }
        
        return ans;
    }
};