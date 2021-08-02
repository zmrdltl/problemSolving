#include <bits/stdc++.h>
using namespace std;
int a, b, diff;
int main(){
    cin >> a >> b;
    diff = a - b;
    if(diff >= 0)
        cout << "Congratulations, you are within the speed limit!";
    else{
        cout << "You are speeding and your fine is $";
        if(1 <= -diff && -diff <= 20) cout << 100;
        else if(21 <= -diff && -diff <= 30) cout << 270;
        else if(-diff >= 31) cout << 500;
        cout << ".";
    }
}