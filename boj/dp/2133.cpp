#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp(int d[], int n){
    if(n == 0) return 1;
    if(n == 1) return 0;
    if(n == 2) return 3;
    int &ret = d[n];
    if(ret != -1) return ret;
    ret = 3 * dp(d, n-2);
    for(int i = 4; i <= n; i += 2)
        ret += 2 * dp(d,n-i);
    return ret;
}

int main(){
    int d[31], n;
    cin >> n;
    memset(d,-1,sizeof(d));
    cout << dp(d, n);
}