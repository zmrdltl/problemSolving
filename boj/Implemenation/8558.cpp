#include <bits/stdc++.h>
using namespace std;
int n, ans = 1;
int main(){
    cin >> n;
    for(int i = 1; i <= n; ans *= i, ans %= 10, i++);
    cout << ans;
}