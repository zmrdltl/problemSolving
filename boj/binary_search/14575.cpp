//TODO
#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Drinking { ll l, r; };
vector <Drinking> participants(1001);
ll totalDrink, n;

ll bs(){
    ll l = 0;
    ll r = 0x3f3f3f3f;

    while(l<=r){
        ll mid = (l+r)/2;
        ll sum = 0;
        ll ans = 0;
        bool cant = 0;
        for(int i = 0; i < n; i++){
            if(participants[i].l > mid) {cant = 1; break;}
        }
        //cout << l << ' ' << mid << ' ' << r << '\n';
        if(cant) l = mid + 1;
        else r = mid - 1;
    }
    if(l*n == totalDrink) return l;
    if((l-1)*(n-1) + l == totalDrink) return l;
    if(l * n <= totalDrink) return l;
    return -1;
}

int main(){
    cin >> n >> totalDrink;
    for(int i = 0; i < n; i++){
        cin >> participants[i].l >> participants[i].r;
    }
    cout << bs() <<'\n';
}