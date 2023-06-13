class Solution {
public:
    string getBinString(int n) {
        string bin;
        while(n) {
            bin += to_string(n % 2);
            n /= 2;
        }
        return bin;
    }
    bool hasAlternatingBits(int n) {
        string bin = getBinString(n);
        for(int i = 0; i < bin.size() - 1; i++) {
            if(bin[i] == bin[i+1]) return false;
        }
        return true;
    }
};