#include <bits/stdc++.h>
using namespace std;

int t, a, b, ans;
map <int, int> m;

int main(){
    for(int i = 1; i*i <= 2000000000/i; i++) m[i] = i*i*i;
    cin >> t;
    for(int i = 1; i <= t; i++){
        ans = 0;
        cin >> a >> b;
        for(auto el : m){
            int pCube = el.second;
            if(a <= pCube && pCube <= b) ans++;
        }
        printf("Case #%d: %d\n", i, ans);
    }
}