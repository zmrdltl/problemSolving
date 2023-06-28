class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto ans = upper_bound(letters.begin(), letters.end(), target);
        if(ans == letters.end()) return letters[0];
        return *ans;
    }
};