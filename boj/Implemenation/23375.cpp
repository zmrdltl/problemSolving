#include <bits/stdc++.h>
using namespace std;
int x, y, radius;
int main(){
    cin >> x >> y >> radius;
    cout << x - radius << ' ' << y + radius << '\n';
    cout << x + radius << ' ' << y + radius << '\n';
    cout << x + radius << ' ' << y - radius << '\n';
    cout << x - radius << ' ' << y - radius << '\n';
}