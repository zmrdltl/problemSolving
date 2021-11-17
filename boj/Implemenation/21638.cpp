#include <bits/stdc++.h>
using namespace std;
int t1, v1, t2, v2;
int main(){
    cin >> t1 >> v1 >> t2 >> v2;
    if(t2 < 0 && v2 >= 10) { cout << "A storm warning for tomorrow! Be careful and stay home if possible!"; return 0;}
    if(t1 > t2) {cout << "MCHS warns! Low temperature is expected tomorrow."; return 0;}
    if(v1 < v2) {cout << "MCHS warns! Strong wind is expected tomorrow."; return 0;}
    cout << "No message";
}