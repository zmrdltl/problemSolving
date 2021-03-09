#include <iostream>
#include <cstring>
#define MOD 1'000'000'007
using namespace std;
int d[1000001];

int dp(int d[],int n){
    if(n == 0) return 1;
    if(n == 1) return 2;
    if(n == 2) return 7;
    int &ret = d[n];
    if(ret != -1) return ret;
    ret = 3 * dp(d,n-2) + 2 * dp(d,n-1);
    for(int i = 3; i <= n; i++){
        ret += (2 * dp(d,n-i)) % MOD;
    }
    return ret % MOD;
}
int main(){
    int n;
    cin >> n;
    memset(d,-1,sizeof(d));
    cout << dp(d,n);

}