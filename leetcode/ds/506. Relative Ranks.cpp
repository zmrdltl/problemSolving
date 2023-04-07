class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector <string> ans(score.size());
        map<int ,int> scoreMap;
        for(int i = 0; i < score.size(); i++) {
            scoreMap[score[i]] = i;
        }
        int rank = score.size();
        for(auto sm : scoreMap) {
            if(rank == 1) {
                ans[sm.second] = "Gold Medal";
            } else if (rank == 2) {
                ans[sm.second] = "Silver Medal";
            } else if(rank == 3) {
                ans[sm.second] = "Bronze Medal";
            } else {
                ans[sm.second] = to_string(rank);
            }
            rank--;
        }
        return ans;
    }
};