#include <bits/stdc++.h>
using namespace std;
int d,h,m;
int main(){
    cin >> d >> h >> m;
    int pivot = 11 + 11 * 60 + 11 * 60 * 24;
    int ans = m + h * 60 + d * 60 * 24 - pivot;
    if(ans < 0 ) cout << -1 <<'\n';
    else cout << ans <<'\n';
}