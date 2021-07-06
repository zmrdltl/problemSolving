#include <bits/stdc++.h>
#define INF 0x3f3f3f3f;
using namespace std;
int n, d[3], d2[3];
int main(){
    cin >> n;
    for(int i = 0; i < 3; i++) cin >> d[i], d2[i] = d[i];

    for(int i = 1,a,b,c; i < n; i++){
        cin >> a >> b >> c;
        
        int b1 = max(d[0], d[1]) + a;
        int b2 = max({d[0], d[1], d[2]}) + b;
        int b3 = max(d[1], d[2]) + c;

        int s1 = min(d2[0], d2[1]) + a;
        int s2 = min({d2[0], d2[1], d2[2]}) + b;
        int s3 = min(d2[1], d2[2]) + c;

        d[0] = b1, d[1] = b2, d[2] = b3;
        d2[0] = s1, d2[1] = s2, d2[2] = s3;
    }

    cout << max({d[0],d[1],d[2]}) << ' ' << min({d2[0],d2[1],d2[2]});

}