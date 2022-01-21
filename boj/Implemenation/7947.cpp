#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
    cin >> t;
    while(t--){
        double sr = 0, sg = 0, sb = 0, r, g, b;
        for(int i = 0; i < 10; i++){
            cin >> r >> g >> b;
            sr += r, sg += g, sb += b;
        }
        cout << (int)round(sr/10) << ' ' << (int)round(sg/10) << ' ' << (int)round(sb/10) << '\n';
    }
}