//top down
class Solution {
    int d[1001];
public:
    Solution() {
        memset(d,0,sizeof(d));
    }
    int dp(int depth, vector<int>& cost) {
        if(depth < 0) return 0;
        int &ret = d[depth];
        if(ret!=0) return ret;
        ret = cost[depth] + min(dp(depth - 1, cost), dp(depth - 2, cost));
        return ret;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min(dp(cost.size() -1, cost), dp(cost.size() -2, cost));
    }
};

//bottom up
class Solution {
    int d[1001];
public:
    Solution() {
        memset(d,0,sizeof(d));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        d[0] = cost[0];
        d[1] = cost[1];
        int sz = cost.size();
        for(int i = 2; i < sz; i++) {
            d[i] = cost[i] + min(d[i-1], d[i-2]);
        }

        return min(d[sz-1], d[sz-2]);
    }
};