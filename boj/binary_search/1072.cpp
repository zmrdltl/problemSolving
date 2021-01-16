#include <bits/stdc++.h>
#define ll long long
#define MAX 1000000000
using namespace std;
ll game,win;
ll binarySearch(){
    ll l = 0;
    ll r = MAX;
    ll firstZ = 100 * win /game;
    if(firstZ >= 99) return -1;

    while(l<=r){
        ll mid = (l+r) / 2;
        ll z = 100 * (mid+win)/(mid+game);
        if(firstZ < z) r = mid - 1;
        else l = mid + 1;
    }

    return l;
}
int main(){
    cin >> game >> win;
    cout << binarySearch() <<'\n';
}