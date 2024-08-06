class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, vector<int>> m;
        for(auto e : edges) {
            m[e[0]].push_back(e[1]);
            m[e[1]].push_back(e[0]);
        }
        int nodeCnt = m.size();
        int ans = -1;
        for(auto el : m) {
            if(el.second.size() == nodeCnt - 1) {
                ans = el.first;
                break;
            }
        }
        return ans;
    }
};