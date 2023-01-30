class Solution {
public:
    vector <int> d;
    Solution(){
        d = vector <int>(40,0);
    }    
    int tribonacci(int n) {
        if(!n) return 0;
        if(n == 1 || n == 2) return 1;
        int &ret = d[n];
        if(ret != 0) return ret;
        return ret = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
};