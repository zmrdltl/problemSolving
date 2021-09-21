#include <bits/stdc++.h>
using namespace std;
int n, a[2001], d[2001][2001];

int dp(int l, int r, int day){
    if(l > r) return 0;
    int &ret = d[l][r];
    if(ret != -1) return ret;
    return ret = max(a[l] * day + dp(l + 1, r, day+1), a[r] * day + dp(l, r - 1, day + 1));
}

int main(){
    memset(d, -1, sizeof(d));
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << dp(0, n-1, 1);
}