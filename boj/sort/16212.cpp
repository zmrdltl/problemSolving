#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> v;
int main(){
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    for(auto el : v) cout << el << ' ';
}