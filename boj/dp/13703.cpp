#include <iostream>
#include <cstring>
#define ll long long
using namespace std;
ll height,second;
ll flee[1000][1000];

ll dp(ll k,ll n){
    ll &ret = flee[k][n];
    if(ret!=-1) return ret;
    if(k==0) return 0;
    if(!n) return 1;

    ret = dp(k+1,n-1) + dp(k-1,n-1);
    return ret;

}
int main(){
    cin >> height >> second;
    memset(flee,-1,sizeof(flee));
    cout << dp(height,second);
}