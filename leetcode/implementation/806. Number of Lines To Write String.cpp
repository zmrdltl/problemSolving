class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int lastLineWidth = 0;
        for(auto c : s) {
            if(lastLineWidth + widths[c-'a']> 100) {
                lastLineWidth = widths[c-'a'];
                lines++;
            } else {
                lastLineWidth += widths[c-'a'];
            }
        }
        return {lines, lastLineWidth};
    }
};