#include <bits/stdc++.h>
using namespace std;
struct Consulting { int conTime, price; };
int n, d[16];
vector <Consulting> c;

int dp(int t){
    if(t >= n) return 0;
    int &ret = d[t];
    if(ret != -1) return ret;
    ret = 0;
    if(t + c[t].conTime <= n)    
        ret = max(ret, dp(t + c[t].conTime) + c[t].price);
    ret = max(ret, dp(t+1));
    return ret;
}

int main(){
    memset(d,-1,sizeof(d));
    cin >> n;
    for(int i = 0,t,p; i < n; i++){
        cin >> t >> p;
        c.push_back({t,p});
    }
    cout << dp(0);
}