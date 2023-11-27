class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int direct = 0, total = 0;
        int sz = distance.size();

        int st = min(start, destination);
        int en = max(start, destination);

        for(int i = 0; i < sz; i++) {
            total += distance[i];
        }
        for(int i = st; i < en; i++) {
            direct += distance[i];
        }
        return min(direct, total - direct);
    }
};