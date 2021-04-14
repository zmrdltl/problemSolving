#include <bits/stdc++.h>
using namespace std;
int t, n;
int paper[501];
int d[501][10001];

int dp(int n, int m){

    int &ret = d[n][m];
    if(ret != -1) return ret;
    
    return ret;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        memset(d,-1,sizeof(d));
        for(int i = 0; i < n; i++) cin >> paper[i];

    }
}