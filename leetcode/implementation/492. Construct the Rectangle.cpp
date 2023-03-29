class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector <int> v;
        for(int i = 1; i <= area; i++) {
            if(area % i == 0) v.push_back(i);
        }
        int mid = v.size() / 2;
        if(v.size() % 2) {
            return {v[mid], v[mid]};
        }
        return {v[mid], v[mid-1]};
    }
};