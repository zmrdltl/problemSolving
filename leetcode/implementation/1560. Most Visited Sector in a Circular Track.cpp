class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector <int> visited;
        vector <int> visitedPerSector(n, 0);
        visitedPerSector[rounds[0] - 1]++;
        for(int i = 1; i < rounds.size(); i++) {
            int start = rounds[i - 1];
            int end = rounds[i];
            while(start != end) {
                start = start % n + 1;
                visitedPerSector[start - 1]++;
            }
        }
        int maxVisited = 0;
        for(auto v : visitedPerSector) {
            maxVisited = max(maxVisited, v);
        }
        for(int i = 0; i < n; i++) {
            if(visitedPerSector[i] == maxVisited) {
                visited.push_back(i+1);
            }
        }
        return visited;
    }
};