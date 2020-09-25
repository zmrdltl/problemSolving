#include <bits/stdc++.h>
using namespace std;
int num, n;
int d[1000][3];
int milk[1000];
int dp(int n,int k){
    int &ret = d[n][k];
    if(ret!=-1) return ret;
    if(n==num) return 0;
    if(milk[n] == k) ret = dp(n+1,(k+1)%3) + 1;
    ret = max(ret, dp(n+1,k));
    return ret;
}
int main(){
    cin >> n;
    num = n;
    for(int i = 0; i < n; i++){
        cin >> milk[i];
    }
    memset(d,-1,sizeof(d));
    cout << dp(0,0);
}