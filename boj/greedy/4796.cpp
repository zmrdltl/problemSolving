#include <bits/stdc++.h>
using namespace std;
int main(){
    int l,p,v;
    int caseCnt = 0;
    while(1){
        cin >> l >> p >> v;
        if(!l && !p && !v) break;
        caseCnt++;
        int ans = v/p*l;
        if(v%p <= l) ans += v%p;
        else ans += l;
        printf("Case %d: %d\n",caseCnt,ans);
    }
}