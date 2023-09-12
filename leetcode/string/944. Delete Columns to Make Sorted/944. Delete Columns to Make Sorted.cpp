class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int columnsToDelete = 0;
        for(int i = 0; i < strs[0].size(); i++) {
            bool isNotLexicographically = false;
            for(int j = 0; j < strs.size() - 1; j++) {
                if(strs[j][i] > strs[j+1][i]) {
                    isNotLexicographically = true;
                    break;
                }
            }
            if (isNotLexicographically) columnsToDelete++;
        }
        return columnsToDelete;
    }
};