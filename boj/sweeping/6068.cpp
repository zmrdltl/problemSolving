#include <bits/stdc++.h>
using namespace std;
struct Work {int timeNeed, endTime; };
int n, ans=0x3f3f3f3f;
vector <Work> v;
bool cmp(Work &a, Work &b){
    if(a.endTime == b.endTime) return a.timeNeed < b.timeNeed;
    return a.endTime < b.endTime;
}
int main(){
    cin >> n;
    for(int i = 0,t,e; i < n; i++){
        cin >> t >> e;
        v.push_back({t,e});
    }
    sort(v.begin(),v.end(),cmp);
    for(int i = n-1; i >= 0; i--){
        ans = min(ans, v[i].endTime);
        ans -= v[i].timeNeed;
    }
    if(ans < 0) cout << -1;
    else cout << ans;
}