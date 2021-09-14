#include <bits/stdc++.h>
using namespace std;
int a[3];
bool f1, f2; //정삼각형이면 f1 = true, 직각삼각형이면 f2 = true
int main(){
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if(a[0] == a[1] && a[1] == a[2]) f1 = true;
    if(a[2] * a[2] == a[0] * a[0] + a[1] * a[1]) f2 = true;
    if(!f1 && !f2) cout << 0;
    if(!f1 && f2) cout << 1;
    if(f1 && !f2) cout << 2;
}