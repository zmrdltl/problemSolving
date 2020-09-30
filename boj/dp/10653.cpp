#include <bits/stdc++.h>
using namespace std;
int n,k;
vector <pair<int,int>> v(1000);

int a[501][501];
int d[501][501];

int dp(int n,int k){
    int &ret = d[n][k];
    if(ret!=-1) return ret;
    if(n==1) return 0;

    ret = 0x7f7f7f7f;

    for(int i  = 0; i <= k; i++){
        if(1 <= n-i-1) ret = min(dp(n-i-1,k-i) + a[n-i-1][n],ret);
    }

    return ret;
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i ++){
        cin >> v[i].first >> v[i].second;
    }
    
    memset(d,-1,sizeof(d));
    for(int i = 1; i <= n-1; i++){
        for(int j = i+1; j <= n; j++){
            a[i][j] = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
        }
    }

    cout << dp(n,k);
}