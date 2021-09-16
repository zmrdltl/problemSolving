#include <bits/stdc++.h>
using namespace std;
double a[2], ans;
int main(){
    cin >> a[0] >> a[1];
    sort(a, a + 2);
    if(a[0] * 3 < a[1]) ans = a[0];
    else if(a[0] * 1.5 < a[1]) ans = a[1] / 3;
    else ans = a[0] / 2;
    printf("%.3f", ans);
}