#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    vector <int> v(n);
    for(auto &n : v) cin >> n;
    if(!next_permutation(v.begin(),v.end())) cout << -1 << '\n';
    else for(auto &n : v) cout << n << ' ';
}