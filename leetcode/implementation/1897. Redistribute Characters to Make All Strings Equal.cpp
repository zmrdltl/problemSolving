class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map <char, int> alphaMap;
        for(auto w : words) {
            for(auto c : w) {
                alphaMap[c]++;
            }
        }
        for(auto el : alphaMap) {
            if (el.second % words.size()) return false;
        }
        return true;
    }
};