class Solution {
public:
    int getTotalMinute(string timePoint) {
        int time = stoi(timePoint.substr(0,2));
        int minute = stoi(timePoint.substr(3));
        int totalMinute = time * 60 + minute;
        return totalMinute;
    }

    int findMinDifference(vector<string>& timePoints) {
        vector <int> minutes;
        for(auto t : timePoints) {
            minutes.push_back(getTotalMinute(t));
        }
        sort(minutes.begin(), minutes.end());
        for(auto m : minutes) cout << m << ' ';
        int minDiff = 0x3f3f3f3f;
        
        for (int i = 1; i < minutes.size(); ++i) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }
        int nextDay = 1440 + minutes[0];
        int circularDiff = (nextDay - minutes.back());
        minDiff = min(minDiff, circularDiff);

        return minDiff;
    }
};