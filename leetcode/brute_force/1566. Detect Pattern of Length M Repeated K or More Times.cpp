class Solution {
public:
    bool isPattern(vector<int>&arr, int start, int m) {
        for (int s = start; s < start + m; s++) {
            if (s >= arr.size() || arr[s-m] != arr[s]) return false;
        }
        return true;
    }

    bool containsPattern(vector<int>& arr, int m, int k) {
        int patternCount = 0;
        for(int start = 0; start < arr.size(); start++) {
            patternCount = 1;
            for(int i = start+m; i < arr.size(); i+=m) {
                if(isPattern(arr, i, m)) {
                    patternCount++;
                } else {
                    break;
                }
            }
            if(patternCount >= k) {
                return true;
            }
        }
        return false;
    }
};