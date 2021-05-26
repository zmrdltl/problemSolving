#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t, n;
ll d[10001];

ll dp(ll num){
    if(num <= 2) return num;

    ll &ret = d[num];
    if(ret != -1) return ret;
    ret = 0;

    ll a = num;
    if(a % 2 == 0) a /= 2;
    else a = a / 2 - 1;
    a /= 3;
    ret = dp(num - 1) + a + 1;
    return ret;
}

int main(){
    cin >> t;
    memset(d,-1,sizeof(d));
    // for(int i = 3; i <= 10000; i++){
    //     ll a = i;
    //     if(a % 2 == 0) a /=2;
    //     else a /= 2, a--;
    //     a /= 3;
    //     d[i] = d[i-1] + a + 1;
    // }
    
    while(t--){
        cin >> n;
        cout << dp(n) << '\n';
    }
}