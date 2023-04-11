class Solution {
public:
    int fibNum[31];
    Solution(){
        memset(fibNum,-1,sizeof(fibNum));
    }
    int fib(int n) {
        if(!n) return 0;
        if(n == 1)return 1;
        int &ret = fibNum[n];
        if(ret != -1) return ret;
        ret = fib(n-1) + fib(n-2);
        return ret;
    }
};