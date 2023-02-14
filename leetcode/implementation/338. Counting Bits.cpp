class Solution {
public:
    string getBitString(int num) {
        string bitString;
        while(num) {
            bitString += to_string(num%2);
            num /= 2;
        }
        return bitString;
    }
    vector<int> countBits(int n) {
        vector <int> ans;
        for(int i = 0; i <= n; i++) {
            string bitString = getBitString(i);
            int cnt = 0;
            for(auto b : bitString) {
                if(b == '1') cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};