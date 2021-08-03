#include <bits/stdc++.h>
using namespace std;
string a,b;
int aScore, bScore, n;
int main(){
    while(1){
        cin >> a >> b;
        if(a == "#" && b == "#" ) break;

        cin >> n;
        aScore = bScore = 0;

        while(n--){
            char c1,c2;
            cin >> c1 >> c2;
            if(c1 == c2) aScore++;
            else bScore++;
        }
        
        cout << a << ' ' << aScore << ' ' << b << ' ' << bScore << '\n';
    }
}