#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    int setA,setC;
    if(n % a == 0) setA = n/a;
    else setA = n/a + 1;

    if(n % c == 0) setC = n / c;
    else setC = n / c + 1;
    cout << min(setA * b , setC * d);
}