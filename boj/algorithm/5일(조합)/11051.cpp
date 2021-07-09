#include <bits/stdc++.h>
#define MOD 10007
using namespace std;
int n,k,a[1001][1001];
//nCk = n-1Ck + n-1Ck-1
int dp(int n, int k){
    if(n == k || k == 0) return 1;
    int &ret = a[n][k];
    if(ret) return ret;
    ret = (dp(n-1,k) % MOD) + (dp(n-1,k-1) % MOD); 
    return ret % MOD;
}

int main(){
    cin >> n >> k;
    cout << dp(n,k);
}
