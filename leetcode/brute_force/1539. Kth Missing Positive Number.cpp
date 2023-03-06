class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map <int, int> arrMap;
        for(auto a : arr) {
            arrMap[a] = 1;
        }
        vector <int> missArr; 
        for(int i = 1; i <= 2000; i++) {
            if(!arrMap.count(i)) {
                missArr.push_back(i);
            }
        }
        return missArr[k-1];
    }
};