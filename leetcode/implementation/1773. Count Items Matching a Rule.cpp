class Solution {
public:
    int getIndexToCompare(string ruleKey) {
        if (ruleKey == "type") return 0;
        if (ruleKey == "color") return 1;
        return 2;
    }

    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int matches = 0;
        for(auto item: items) {
            int idx = getIndexToCompare(ruleKey);
            if (item[idx] == ruleValue) matches++;
        }
        return matches;
    }
};