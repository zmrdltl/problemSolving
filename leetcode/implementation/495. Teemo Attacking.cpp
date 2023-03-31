class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int totalPoisoned = 0;
        int next = 0;
        for(auto t : timeSeries) {
            if(next > t) {
                totalPoisoned += duration - (next - t);
            }
            else {
                totalPoisoned += duration;
            }
            next = t + duration;
        }

        return totalPoisoned;
    }
};