class Solution {
public:
    int xorOperation(int n, int start) {
        vector <int> xors(1, start);
        for(int i = 1; i < n; i++) {
            int x = start + 2 * i;
            xors.push_back(x);
        }

        int s = xors[0];
        for(int i = 1; i < xors.size(); i++) {
            s ^= xors[i];
        }

        return s;
    }
};