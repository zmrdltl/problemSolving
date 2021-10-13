#include <bits/stdc++.h>
using namespace std;
int l, r;
int main(){
    cin >> l >> r;
    if(l != r) cout << "Odd " << max(l,r) * 2;
    else if(!l && !r) cout << "Not a moose";
    else cout << "Even " << l * 2;
}