#include <bits/stdc++.h>
using namespace std;
int a, b, ans;
int main(){
    cin >> a >> b;
    ans = (a + b) % 12;
    if(!ans) ans = 12;
    cout << ans;
}