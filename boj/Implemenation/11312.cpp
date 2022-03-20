#include <bits/stdc++.h>
#define ll long long
using namespace std;
double t, a, b;
int main(){
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << (ll)ceil(a/b * a/b) << '\n';
    }
}