#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int z, a, b, ans;
int main(){
    fastio;
    cin >> z;
    while(z--){
        cin >> a >> b;
        if(b % a) cout << "NIE\n";
        else cout << "TAK\n";
    }
}