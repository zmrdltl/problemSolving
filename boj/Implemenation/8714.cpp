#include <bits/stdc++.h>
using namespace std;
int n, cnt;

int main(){
    cin >> n;
    for(int i = 0, s; i < n; i++) {
        cin >> s;
        if(s) cnt++;
    }
    cout << min(cnt, n - cnt);
}