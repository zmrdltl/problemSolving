class Solution {
public:
    static bool cmp (vector<int> a, vector <int> b) {
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int maxTotalUnits = 0;
        for(int i = 0; i < boxTypes.size() && truckSize > 0; i++) {
            if(boxTypes[i][0] < truckSize) {
                maxTotalUnits += boxTypes[i][0] * boxTypes[i][1];
            } else {
                maxTotalUnits += truckSize * boxTypes[i][1];
            }
            truckSize -= boxTypes[i][0];
        }
        return maxTotalUnits;
    }
};
