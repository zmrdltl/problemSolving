#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n, d[2000][3];
int dp(int len, int sum, int prev){
    if(len == n) {
        if(!sum && prev == 5) return 1;
        return 0;
    }
    int &ret = d[len][sum];
    if(ret != -1) return ret;
    ret = dp(len + 1, (sum + 1) % 3, 1)%MOD + dp(len + 1, (sum + 5) % 3, 5)%MOD;
    return ret%MOD;
}

int main(){
    memset(d, -1, sizeof(d));
    cin >> n;
    cout << dp(0, 0, 0);
}