class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map <int, vector<int>> pieceMap;
        for(auto piece : pieces) {
            pieceMap[piece[0]] = piece;
        }

        for(int i = 0; i < arr.size();) {
            if(pieceMap.find(arr[i]) == pieceMap.end()) {
                return false;
            }
            vector <int> piece = pieceMap[arr[i]];
            for(auto num : piece) {
                if(arr[i++] != num) {
                    return false;
                }
            }
        }
        return true;
    }
};