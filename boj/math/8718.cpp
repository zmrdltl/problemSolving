#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll x, k, a, b, c;
int main(){
    cin >> x >> k;
    if(7000 * k <= 1000 * x) a = 7000 * k;
    if(3500 * k <= 1000 * x) b = 3500 * k;
    if(1750 * k <= 1000 * x) c = 1750 * k;
    cout << max({a,b,c});
}