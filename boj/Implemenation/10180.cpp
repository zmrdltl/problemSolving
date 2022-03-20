#include <bits/stdc++.h>
using namespace std;
double t, n, d, v, f, c;
int main(){
    cin >> t;
    while(t--){
        cin >> n >> d;
        int ans = 0;
        for(int i = 0; i < n; i++){
            cin >> v >> f >> c;
            double dist = v * (f / c);
            if(dist >= d) ans++;
        }
        cout << ans << '\n';
    }
}