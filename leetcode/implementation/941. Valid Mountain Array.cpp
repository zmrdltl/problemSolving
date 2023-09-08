#define DEFAULT -1
#define INCREASING 1
#define MOUNTAIN_ARRAY 2

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int sz = arr.size();
        int stat = DEFAULT;
        int peak = 0;
        for(int i = 0; i < sz - 1; i++) {
            if (arr[i] == arr[i+1]) return false;
            if (arr[i] > arr[i+1]) {
                peak = i;
                break;
            }
            stat = INCREASING;
        }
        for(int i = peak; i < sz - 1; i++) {
            if (arr[i] == arr[i+1]) return false;
            if (arr[i] < arr[i+1]) {
                return false;
            }
            if(stat == INCREASING) stat = MOUNTAIN_ARRAY;
        }
        return stat == MOUNTAIN_ARRAY;
    }
};