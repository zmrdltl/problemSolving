#include <bits/stdc++.h>
using namespace std;
int apple, pear, axel, petra;
int main(){
    cin >> apple >> pear;
    axel = apple * 7;
    petra = pear * 13;
    if(axel > petra) cout << "Axel";
    else if(axel < petra) cout << "Petra";
    else cout << "lika";
}