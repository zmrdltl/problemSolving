#include <bits/stdc++.h>
using namespace std;
int n,k,a[11][11];
//nCk = n-1Ck + n-1Ck-1
int dp(int n, int k){
    if(n == k || k == 0) return 1;
    int &ret = a[n][k];
    if(ret) return ret;
    ret = dp(n-1,k) + dp(n-1,k-1);
    return ret;
}

int main(){
    cin >> n >> k;
    cout << dp(n,k);
}
