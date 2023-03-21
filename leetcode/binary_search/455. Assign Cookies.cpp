class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ans = 0;
        for(auto greed : g) {
            auto it = lower_bound(s.begin(), s.end(), greed);
            if(it == s.end()) continue;
            s.erase(it);
            ans++;
        }
        return ans;
    }
};