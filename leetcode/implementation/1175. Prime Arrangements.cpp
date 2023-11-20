using ll = long long;
const int MOD = 1e9 + 7;
class Solution {
public:
    bool isPrime(int n) {
        if (n == 1) return false;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }

    ll factorial(int n) {
        ll fac = 1;
        for(int i = 2; i <= n; i++) fac = (fac * i) % MOD;
        return fac;
    }

    int numPrimeArrangements(int n) {
        int primeCount = 0;
        for(int i = 2; i <= n; i++) {
            if (isPrime(i)) primeCount++;
        }
        return ((factorial(primeCount) % MOD) * (factorial(n - primeCount) % MOD)) % MOD;
    }
};