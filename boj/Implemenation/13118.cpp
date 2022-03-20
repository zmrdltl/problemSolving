#include <bits/stdc++.h>
using namespace std;
int p[5], x, y, r, ans;
int main(){
    cin >> p[1] >> p[2] >> p[3] >> p[4] >> x >> y >> r;
    for(int i = 1; i <= 4; i++){
        if(x == p[i]) ans = i;
    }
    cout << ans;
}