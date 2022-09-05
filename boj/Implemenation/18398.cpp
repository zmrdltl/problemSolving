#include <bits/stdc++.h>
using namespace std;
int t, n, a, b;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        while(n--){
            cin >> a >> b;
            cout << a + b << ' ' << a * b << '\n';
        }
    }
}