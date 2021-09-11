#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll k, w, m; 
int main(){
    cin >> k >> w >> m; 
    ll result = 0; 
    while (k < w) k += m, result++; 
    cout << result << "\n";
}