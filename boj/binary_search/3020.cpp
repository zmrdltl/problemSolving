#include <bits/stdc++.h>
using namespace std;
int n, height, cnt, ans=0x3f3f3f3f;
vector <int> stalactite,stalagmite; //종유석, 석순
int main(){
    cin >> n >> height;
    for(int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        if(i%2==0) stalagmite.push_back(x);
        else stalactite.push_back(x);
    }

    sort(stalagmite.begin(),stalagmite.end());
    sort(stalactite.begin(),stalactite.end());

    for(int i = 1; i <= height; i++){
        int idx = stalagmite.size() - (lower_bound(stalagmite.begin(),stalagmite.end(),i) - stalagmite.begin());
        int idx2 = stalactite.size() - (upper_bound(stalactite.begin(),stalactite.end(),height-i) - stalactite.begin());
        ans = min(ans,idx + idx2);
    }
    for(int i = 1; i <= height; i++){
        int idx = stalagmite.size() - (lower_bound(stalagmite.begin(),stalagmite.end(),i) - stalagmite.begin());
        int idx2 = stalactite.size() - (upper_bound(stalactite.begin(),stalactite.end(),height-i) - stalactite.begin());
        if(idx+idx2 == ans) cnt++;
    }

    cout << ans << ' ' << cnt << '\n';
}