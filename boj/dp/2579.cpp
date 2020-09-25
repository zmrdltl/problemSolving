#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int stair[301];
int d[301][3];
//TODO 미구현
int dp(int n,int k){
    int &ret = d[n][k];
    if(ret!=-1) return ret;
    if(n==0) return 0;
    for(int i = 1; i<n; i++){
        d[i][2] = dp(i-1,1) + stair[i];
        d[i][1] = max(dp(i-2,i),dp(i-2,2)+stair[i]);
    }
    return ret;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> stair[i];
    memset(d,-1,sizeof(d));
    cout << dp(n,1);
}