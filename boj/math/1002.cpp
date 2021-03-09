#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int x1,y1,r1,x2,y2,r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double a = sqrt((abs(x1-x2)) * (abs(x1-x2)) + (abs(y1-y2)) * (abs(y1-y2)));
        double b = r1;
        double c = r2;
        //cout << "a, b, c : " << a << ' ' << b << ' ' << c << '\n';
        if(!a){
            if(b == c) cout << -1 << '\n';
            else cout << 0 <<'\n';
        }
        else{
            if(a < b + c){
                if(a + min(b,c) == max(b,c)) cout << 1 <<'\n';
                else if(a + min(b,c) < max(b,c)) cout << 0 << '\n';
                else cout << 2 <<'\n';
            }
            else if(a == b + c) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
}
