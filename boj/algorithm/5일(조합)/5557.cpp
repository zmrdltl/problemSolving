#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, num[101], d[101][101];

ll dp(int i, int j){  
    if(i > n - 2 || j < 0 || j > 20) return 0;
    if(i == n - 2 && j == num[n-1]) return 1;
    ll &ret = d[i][j];
    if(ret != -1) return ret;
    ret = 0;
    ret = dp(i + 1,j + num[i + 1]) + dp(i+1,j - num[i + 1]);
    return ret;
}

int main(){
    memset(d,-1,sizeof(d));
    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    cout << dp(0, num[0]);
}