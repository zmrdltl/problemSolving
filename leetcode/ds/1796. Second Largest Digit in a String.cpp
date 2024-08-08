class Solution {
public:
    int secondHighest(string s) {
        set <int> numSet;
        for(auto c : s) {
            if(isdigit(c)) {
                numSet.insert(c-'0');
            }
        }
        if (numSet.size() < 2) {
            return -1;
        }
        
        auto it = numSet.rbegin();
        it++;
        return *it;
    }
};