class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;
        if(s == goal) {
            unordered_set<char> unique_chars(s.begin(), s.end());
            return unique_chars.size() < s.size();
        }
        int diff = 0;
        int firstDiffIdx = -1, secondDiffIdx = -1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == goal[i]) continue;
            diff++;
            if(firstDiffIdx == -1) firstDiffIdx = i;
            else secondDiffIdx = i;
        }
        return diff == 2 && s[firstDiffIdx] == goal[secondDiffIdx] && s[secondDiffIdx] == goal[firstDiffIdx];
    }
};