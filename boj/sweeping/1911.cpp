#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n, l, ans, x;
vector <pii> waterHole;
int main(){
    cin >> n >> l;
    while(n--){
        int x,y;
        cin >> x >> y;
        waterHole.push_back({x,y});
    }
    sort(waterHole.begin(),waterHole.end());

    for(auto &w : waterHole){
        if (x >= w.second) continue;
        x = max(x, w.first); 
        int cnt = (w.second - (x + 1)) / l + 1; 
        ans += cnt; 
        x += l * cnt; 
    }
    cout << ans << '\n';
}