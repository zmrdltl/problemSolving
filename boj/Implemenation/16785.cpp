#include <bits/stdc++.h>
using namespace std;
int a, b, c, coin, day;
int main(){
    cin >> a >> b >> c;
    while(coin < c){
        day++;
        if(day % 7 == 0) coin+=b;
        coin += a;
    }
    cout << day;
}