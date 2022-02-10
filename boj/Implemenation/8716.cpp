#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

ll x1, y11, x2, y2, x3, y3, x4, y4;

int main(){
    cin >> x1 >> y11 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    if(x2 < x3 || x1 > x4 || y11 < y4 || y2 > y3) cout << 0;
    
    else {
        ll lx = max(x1, x3);
        ll rx = min(x2, x4);
        ll ry = max(y2, y4);
        ll ly = min(y11, y3);
        cout << abs((rx - lx) * (ry - ly));
    }
}