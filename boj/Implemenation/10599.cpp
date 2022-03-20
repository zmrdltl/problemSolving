#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main(){
    while(1){
        cin >> a >> b >> c >> d;
        if(!a && !b && !c && !d) break;
        cout << c - b << ' ' << d - a  << '\n';
    }
}