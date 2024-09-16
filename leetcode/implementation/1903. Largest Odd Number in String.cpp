class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int oddIdx = -1;
        for(int i = 0; i < num.size(); i++) {
            if ((num[i] - '0') % 2) oddIdx = i;
        }
        ans = num.substr(0, oddIdx+1);
        return ans;
    }
};
