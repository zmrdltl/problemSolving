#include <bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        int a, b, diff;
        cin >> a >> b;
        if(!a && !b) break;
        diff = a - b;
        if(diff < 2) cout << 0 << ' ' << 0;
        else if(diff % 2) cout << (diff - 3) / 2 << ' ' << 1;
        else cout << diff / 2 << ' ' << 0;
        cout << '\n';
    }
}