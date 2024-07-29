class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1;
        int smallestManhattanDist = 0x3f3f3f3f;
        for(int i = 0; i < points.size(); i++) {
            vector <int> coord = points[i];
            if (coord[0] != x && coord[1] != y) continue;
            int dist = abs(coord[0] - x) + abs(coord[1] - y);
            smallestManhattanDist = min(smallestManhattanDist, dist);
        }

        for(int i = 0; i < points.size(); i++) {
            vector <int> coord = points[i];
            if (coord[0] != x && coord[1] != y) continue;
            int dist = abs(coord[0] - x) + abs(coord[1] - y);
            if(smallestManhattanDist == dist) {
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};