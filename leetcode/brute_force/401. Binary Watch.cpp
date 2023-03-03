class Solution {
public:
    int countBit(int num){
        int count = 0;

        while(num > 0) {
            if((num & 1) == 1) count++;
            num = num >> 1;
        }

        return count;
    }

    string getTimeString(int h, int m) {
        string t = to_string(h) + ":";
        if(m < 10) t += "0";
        t += to_string(m);
        return t;
    }
    
    vector<string> readBinaryWatch(int turnedOn) {
        vector <string> ans;
        for(int h = 0; h <= 11; h++) {
            for(int m = 0; m <= 59; m++) {
                if(countBit(h) + countBit(m) == turnedOn) {
                    
                    ans.push_back(getTimeString(h, m));
                }
            }
        }
        return ans;
    }
};