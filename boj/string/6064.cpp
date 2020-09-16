#include <iostream>
#include <string>
using namespace std;
int t, m, n, x, y;

int gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

int lcm(int a,int b){
    return a*b/gcd(a,b);
}

int main(){
    cin >> t;
    while(t--){
        int year = 0;
        cin >> m >> n >> x >> y;
        year = x % (m + 1);
        int tempY = x;

        for (int i = 0; i < n; i++) {
            int ty = tempY % n == 0 ? n : tempY % n;
            if (ty == y) {
                break;
            }
            tempY = ty + m;
            year += m;
        }
        
        if(lcm(m,n) < year) cout << -1 <<'\n';
        else cout << year <<'\n';
    }
}