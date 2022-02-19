#include <bits/stdc++.h>
#define MAX 0x3f3f3f3f
#define ll long long
using namespace std;
ll n, minX = MAX, maxX = -MAX, minY = MAX, maxY = -MAX;
int main(){
    cin >> n;
    for(ll i = 0, x, y; i < n; i++){
        cin >> x >> y;
        minX = min(x, minX);
        maxX = max(x, maxX);
        minY = min(y, minY);
        maxY = max(y, maxY);
    }
    cout << (maxX - minX) * (maxY - minY);
}