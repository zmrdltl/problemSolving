class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> rank;
        map<int,int> rankMap;
        priority_queue <int, vector<int>, greater<int>>pq;
        for(auto a : arr) {
            pq.push(a);
        }
        int curRank = 1;
        while(pq.size()) {
            if(!rankMap.contains(pq.top())) {
                rankMap[pq.top()] = curRank++;
            }
            pq.pop();
        }
        for(auto a : arr) {
            rank.push_back(rankMap[a]);
        }
        return rank;
    }
};