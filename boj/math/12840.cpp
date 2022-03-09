#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
int h, m, s, q, t, c, sec;
int main(){
    fastio;
    cin >> h >> m >> s >> q;
    sec = h * 3600 + m * 60 + s;
    while(q--){
        cin >> t;
        if(t == 1){
            cin >> c;
            sec = (sec + c) % 86400;
        }
        else if(t == 2){
            cin >> c;
            sec = (sec - c) % 86400;;
            if(sec < 0) sec += 24 * 3600;
        }
        else{
            h = sec / 3600;
            m = sec / 60 % 60;
            cout << h << ' ' << m << ' ' <<  sec % 60 << '\n';
        }
    }
}
