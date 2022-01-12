#include <bits/stdc++.h>
using namespace std;
int a[2], sum, sub;
int main(){
    cin >> a[0] >> a[1];
    sum = a[0] + a[1];
    sub = a[0] - a[1];
    cout << max(sum, sub) << '\n' << min(sum, sub);
}