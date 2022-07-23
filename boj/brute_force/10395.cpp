#include <bits/stdc++.h>
using namespace std;
int a[5];
char c = 'Y';
int main(){
    for(int i = 0; i < 5; i++) cin >> a[i];
    for(int i = 0, x; i < 5; i++) {
        cin >> x;
        if(a[i] == x) c = 'N';
    }
    cout << c;
}