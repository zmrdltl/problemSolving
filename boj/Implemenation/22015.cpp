#include <bits/stdc++.h>
using namespace std;
int a, b, c, upperLimit;
int main(){
    cin >> a >> b >> c;
    upperLimit = max({a, b, c});
    cout << upperLimit - a + upperLimit - b + upperLimit - c;
}