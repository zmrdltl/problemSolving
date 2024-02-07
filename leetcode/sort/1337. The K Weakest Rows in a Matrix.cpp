using pii = pair<int,int>;
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector <pii> soldiersCount;
        for(int i = 0; i < mat.size(); i++) {
            int cnt = 0;
            for(int j = 0; j < mat[0].size(); j++) {
                if(mat[i][j]) cnt++;
            }
            soldiersCount.push_back({cnt, i});
        }
        sort(soldiersCount.begin(), soldiersCount.end());
        vector <int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(soldiersCount[i].second);
        }
        return ans;
    }
};