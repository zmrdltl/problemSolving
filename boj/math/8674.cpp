#include <bits/stdc++.h>
using namespace std;
long long a[2];
int main(){
    cin >> a[0] >> a[1];
    if(!(a[0] % 2) || !(a[1] % 2)) cout << 0;
    else cout << min(a[0], a[1]);
}