class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        for(auto word : words) {
            int isAllowed = 1;
            for(char w : word) {
                if(allowed.find(w) == string::npos) {
                    isAllowed = 0;
                    break;
                }
            }
            if(isAllowed) count++;
        }
        return count;
    }
};