#include <bits/stdc++.h>
using namespace std;
int a, b, n, minMove = 0x3f3f3f3f;
int main(){
    cin >> a >> b >> n;
    for(int i = 0, button; i < n; i++) {
        cin >> button;
        minMove = min(minMove, abs(button - b) + 1);
    }
    cout << min(minMove, abs(a-b));
}