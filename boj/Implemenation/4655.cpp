#include <bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        int cnt = 1;
        double c, length = 0;
        cin >> c;
        if(c == 0.0) break;
        for(int i = 1; ; i++) {
            length += 1.0 / (i+1);
            if(length >= c) {cnt = i; break;}
        }
        cout << cnt << " card(s)\n";
    }
}