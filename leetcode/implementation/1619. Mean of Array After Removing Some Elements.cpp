class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int removeCnt = (double) arr.size() * 0.05;
        double avg = 0;
        for(int i = removeCnt; i < arr.size() - removeCnt; i++) {
            avg += arr[i];
        }
        avg /=  arr.size() - removeCnt * 2;
        return avg;
    }
};