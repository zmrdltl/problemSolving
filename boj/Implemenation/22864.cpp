#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a, b, c, m, work, tired;
int main(){
    cin >> a >> b >> c >> m;
    for(int i = 1; i <= 24; i++){
        if(tired + a <= m){
            tired += a;
            work += b;
        }
        else{
            tired -= c;
            if(tired < 0) tired = 0;
        }
    }
    cout << work;
}