#include <bits/stdc++.h>
using namespace std;
int a, b, n, ans;
int main(){
    cin >> a >> b >> n;
    for(int i = 0; i < n+1; i++){
        ans = a / b;
        a = a%b * 10;
    }
    cout << ans;
}