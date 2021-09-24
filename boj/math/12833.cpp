#include <bits/stdc++.h>
using namespace std;
int a,b,c,ans;
int main(){
    cin >> a >> b >> c;
    if(c % 2) ans = a ^ b;
    else ans = a;
    cout << ans;
}