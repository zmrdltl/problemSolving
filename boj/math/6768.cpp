#include <bits/stdc++.h>
using namespace std;
int n, ans = 1;
int main(){
    cin >> n;
    for(int i = 1; i <= 3; i++) ans *= n - i;
    cout << ans / 6;
}