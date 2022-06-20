#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll ans;
vector <int> v;

int main(){
    cin >> n;
    v.resize(n);

    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            auto el = lower_bound(v.begin() + j + 1, v.end(), -(v[i] + v[j])) - v.begin();
            auto el2 = upper_bound(v.begin() + j + 1, v.end(), -(v[i] + v[j])) - v.begin();
            if(el == n) continue;
            if(v[i] + v[j] + v[el] == 0) ans += el2 - el;
        }
    }

    cout << ans;
}