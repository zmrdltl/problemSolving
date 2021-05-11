#include <bits/stdc++.h>
using namespace std;
int n, d[3], d2[3];
int main(){
    cin >> n;
    for(int i = 0; i < 3; i++) cin >> d[i], d2[i] = d[i];

    for(int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        int firstBig = max(d[0],d[1]) + a;
        int firstSmall = min(d2[0],d2[1]) + a;

        int secondBig = max({d[0],d[1],d[2]}) + b;
        int secondSmall = min({d2[0],d2[1],d2[2]}) + b;

        int thirdBig = max(d[1],d[2]) + c;
        int thirdSmall = min(d2[1],d2[2]) + c;

        d[0] = firstBig;
        d[1] = secondBig;
        d[2] = thirdBig;

        d2[0] = firstSmall;
        d2[1] = secondSmall;
        d2[2] = thirdSmall;
    }
    cout << max({d[0],d[1],d[2]}) << ' ' << min({d2[0],d2[1],d2[2]});
}