using pii = pair<int,int>;
class Solution {
public:
    int findLHS(vector<int>& nums) {
        vector <int> hs;
        map <int, int> numsMap;
        for(auto n : nums) {
            numsMap[n]++;
        }

        vector <pii> v;
        
        for(auto n : numsMap) {
            v.push_back({n.first, n.second});
        }
        int maxFre = 0;
        for(int i = 0; i < v.size() -1; i++) {
            if(abs(v[i].first - v[i+1].first) == 1)
                maxFre = max(maxFre, v[i].second + v[i+1].second);
        }
        int one, two;
        for(int i = 0; i < v.size() -1; i++) {
            if(maxFre == v[i].second + v[i+1].second) {
                one = v[i].first;
                two = v[i+1].first;
                break;
            }
        }
        for(auto n : nums) {
            if(n == one || n == two) {
                hs.push_back(n);
            }
        }
        return hs.size();
    }
};