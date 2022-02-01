#include <bits/stdc++.h>
using namespace std;
int x, k, a;
int main(){
    cin >> x >> k >> a;
    if(x % (k + a) < k) cout << 1;
    else cout << 0;
}