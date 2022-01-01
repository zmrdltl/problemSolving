#include <bits/stdc++.h>
#define ll long long
using namespace std;
double h, w, n, m;
int main(){
    cin >> h >> w >> n >> m;
    cout << (ll)ceil(h / (n+1)) * (ll)ceil(w / (m+1));
}