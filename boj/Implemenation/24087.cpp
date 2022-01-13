#include <bits/stdc++.h>
using namespace std;
int price = 250;
double a, b, s;
int main(){
    cin >> s >> a >> b;
    if(s <= a) cout << price;
    else cout << price + 100 * ceil((s - a)/b);
}