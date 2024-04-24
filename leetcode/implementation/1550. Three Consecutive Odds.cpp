class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if (arr.size() < 3) return false;
        for(int i = 0; i < arr.size() - 2; i++) {
            int a = arr[i];
            int b = arr[i+1];
            int c = arr[i+2];
            if (a % 2 && b % 2 && c % 2) return true;
        }
        return false;
    }
};