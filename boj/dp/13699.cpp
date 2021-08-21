#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t[36], n;

ll dp(int num){
    if(num < 0) return 0;
    if(num == 1 || num == 0) return 1;

    ll &ret = t[num];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = 0; i < n; i++) ret += dp(num - i - 1) * dp(i);
    
    return ret;
}

int main(){
    memset(t,-1,sizeof(t));
    cin >> n;
    cout << dp(n);
}