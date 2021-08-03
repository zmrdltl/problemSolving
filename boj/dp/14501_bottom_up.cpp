#include <bits/stdc++.h>
using namespace std;
struct Consulting {int conTime, price; };
int n, ans;
int d[16];

vector <Consulting> plan;
int main(){
    cin >> n;
    for(int i = 1,t,p; i <= n; i++){
        cin >> t >> p;
        plan.push_back({t,p});
    }
    for(int i = 0; i <= n; i++){
        d[i] = max(d[i],d[i-1]);
        if(i + plan[i].conTime <= n ){
            d[i+plan[i].conTime] = max(d[i+plan[i].conTime], d[i] + plan[i].price);
        }
    }

    for(int i = 1; i <= n; i++) ans = max(ans,d[i]);
    cout << ans;
}