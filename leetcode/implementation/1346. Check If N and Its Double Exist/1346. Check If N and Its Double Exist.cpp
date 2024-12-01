class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            for(int j = 0; j < arr.size(); j++) {
                if(i == j) continue;
                if(arr[i] == 2 * arr[j]) return true;
            }
        }
        return false;
    }
};