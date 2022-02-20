#include <bits/stdc++.h>
using namespace std;
int t, w, k;
int main(){
    cin >> t;
    while(t--){
        cin >> w >> k;
        if(!(w % 2) && !(k % 2))
            cout << w / 2 * k;
        else if(!(w % 2))
            cout << w / 2 * k;
        else if(!(k % 2))
            cout << k / 2 * w;
        else 
            cout << min(w, k) / 2 * max(w, k) + max(w, k) / 2;
        cout << '\n';
    }
}