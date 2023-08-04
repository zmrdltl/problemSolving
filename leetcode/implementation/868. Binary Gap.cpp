class Solution {
public:
    string getString(int n) {
        string bin;
        while(n) {
            bin += to_string(n % 2);
            n /= 2;
        }
        reverse(bin.begin(), bin.end());
        return bin;
    }

    int binaryGap(int n) {
        string s = getString(n);
        vector <int> idxs;
        int dist = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                idxs.push_back(i);
            }
        }
        if(idxs.size() < 2) return 0;
        for(int i = 1; i < idxs.size(); i++) {
            dist = max(dist, idxs[i] - idxs[i-1]);
        }
        return dist;
    }
};