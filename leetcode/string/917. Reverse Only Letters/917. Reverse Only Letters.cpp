class Solution {
public:
    string reverseOnlyLetters(string s) {
        int j = s.size() - 1;
        string ans = s;

        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) {
                while (!isalpha(s[j])) j--;
                ans[i] = s[j--];
            }
        }

        return ans;
    }
};