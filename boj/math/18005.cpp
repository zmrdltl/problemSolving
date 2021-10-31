#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
ull n;
int main(){
    cin >> n;
    if(n % 2) cout << 0;
    else {
        if(n * (n+1) / 2 % 2) cout << 1;
        else cout << 2;
    }
}