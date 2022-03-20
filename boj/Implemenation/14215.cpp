#include <bits/stdc++.h>
using namespace std;
int a[3];
int main(){
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if(a[0] + a[1] > a[2]) cout << a[0] + a[1] + a[2];
    else cout << (a[0] + a[1]) * 2 - 1;
}