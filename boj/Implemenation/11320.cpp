#include <bits/stdc++.h>
using namespace std;
double t, a, b;
int main(){
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << (int)ceil((a*a) / (b*b)) << '\n';
    }
}