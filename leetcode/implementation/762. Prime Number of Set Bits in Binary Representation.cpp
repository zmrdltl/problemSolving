class Solution {
public:
    vector <int> primeCheck;

    Solution(){
        primeCheck.resize(1000001,1);
        primeCheck[1] = 0;
        for(int i = 2; i * i <= 1000000; i++) {
            if(!primeCheck[i]) continue;
            for(int j = i + i; j <= 1000000; j += i) primeCheck[j] = 0;
        }
    }

    int getSetBits(int num){
        int bits=0;
        while(num) {
            if(num & 1) bits++;
            num >>= 1;
        }
        return bits;
    }

    bool isPrime(int num) {
        return primeCheck[num];
    }

    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i = left; i <= right; i++) {
            if(isPrime(getSetBits(i))) {
                ans++;
            }
        }
        return ans;
    }
};