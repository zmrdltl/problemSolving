#include <bits/stdc++.h>
using namespace std;
double x,y,z;
int main(){
    cin >> x >> y >> z;
    if(x + y <= z + 0.5) cout << 1;
    else cout << 0;
}