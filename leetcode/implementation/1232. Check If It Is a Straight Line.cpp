class Solution {
public:
    double getInclination(vector<int> coordA, vector<int> coordB) {
      if(coordB[0] - coordA[0] == 0) return 0;
      return (coordB[1] - coordA[1]) / (coordB[0] - coordA[0]);
    }

    bool checkStraightLine(vector<vector<int>>& coordinates) {
      for(int i = 0; i < coordinates.size() - 2; i++) {
        if(getInclination(coordinates[i], coordinates[i + 1]) != getInclination(coordinates[i + 1], coordinates[i + 2])) {
          return false;
        }
      }
      return true;
    }
};