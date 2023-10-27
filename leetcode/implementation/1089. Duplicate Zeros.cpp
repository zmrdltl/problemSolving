class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector <int> ans;
        vector <int> v;
        for(auto a : arr) {
            if(a) v.push_back(a);
            else v.push_back(0),v.push_back(0);
        }
        for(int i = 0; i < arr.size(); i++) {
            ans.push_back(v[i]);
        }
        arr = ans;
    }
};