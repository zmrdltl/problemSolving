#include <bits/stdc++.h>
using namespace std;
int a[3], b[3], ans; //닭고기, 쇠고기, 파스타
int main(){
    for(int i = 0; i < 3; i++) cin >> a[i];
    for(int i = 0; i < 3; i++) cin >> b[i];
    for(int i = 0; i < 3; i++) {
        if(a[i] < b[i]) ans += b[i] - a[i];
    }
    cout << ans;
}