#include <bits/stdc++.h>
using namespace std;
int a,x,b,y,T,option1,option2;
int main(){
    cin >> a >> x >> b >> y >> T;

    if(T > 30) option1 = a + (T - 30) * x * 21;
    else option1 = a;

    if(T > 45) option2 = b + (T - 45) * y * 21;
    else option2 = b;
    
    cout << option1 << ' ' << option2;
}