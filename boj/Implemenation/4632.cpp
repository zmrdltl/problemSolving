#include <bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        int a[2], b[2], percent = 0;
        cin >> a[0] >> a[1] >> b[0] >> b[1];
        if(!a[0] && !a[1] && !b[0] && !b[1]) break;
        sort(a, a + 2);
        sort(b, b + 2);
        
        while(1) {
            double q = (double)a[0] * (100 - percent) / 100;
            double w = (double)a[1] * (100 - percent) / 100;
            if(q <= (double)b[0] && w <= (double)b[1]) break;
            percent++;
        }
        cout << 100 - percent << "%" << '\n';
    }
}