#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main(){
    while(cin >> a >> b >> c){
        cout << max(b-a, c-b) - 1 << '\n';
    }
}