#include <bits/stdc++.h>
#defube 
using namespace std;
int n,m;
vector <int> v;
//k개로 n을 만드는 경우의 수 d
//d[i][j] = d[i-1][1 ~ j ~ n-1] + 1
int d[201][201];
int dp(int i, int j){
    if(i==0) return 1;
    int &ret = d[i][j];
    if(ret != -1) return ret;
    for(int t = 1; t < n; t++)
        ret += (dp(i-1,t) + 1) ;

    return ret;
}

int main(){
    cin >> n >> m;
    memset(d,-1,sizeof(d));
    dp(k,n);
}