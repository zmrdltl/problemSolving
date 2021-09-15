#include <bits/stdc++.h>
using namespace std;
int cow[11];
int n, ans;
int main(){
    memset(cow,-1,sizeof(cow));
    cin >> n;
    while(n--) {
        int a, b;
        cin >> a >> b;
        if(cow[a] != -1 && cow[a] != b) ans++;
        cow[a] = b;
    }
    cout << ans;
}