#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll d[101][101],ck[101][101];
ll dp(int n, int m, int i, int j){
    if(i < 0 || j < 0 || ck[i][j]) return 0;
    if(!i&&!j) return 1;
    ll &ret = d[i][j];
    if(ret!=-1) return ret;
    ret = dp(n,m,i-1,j) + dp(n,m,i,j-1);
    return ret % 1000000007;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    memset(d,-1,sizeof(d));
    memset(ck,0,sizeof(ck));
    for(auto p : puddles) ck[p[1]-1][p[0]-1] = 1;
    return  dp(n,m,n-1,m-1);
}