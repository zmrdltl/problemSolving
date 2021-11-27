#include <bits/stdc++.h>
using namespace std;

int main(){
    while(1){
        int budget, amount, result;
        char op;
        cin >> budget >> op >> amount;
        if(!budget && op == 'W' && !amount) break;
        if(op == 'W') result = budget - amount;
        else result = budget + amount;
        if(result < -200) cout << "Not allowed\n";
        else cout << result << '\n';
    }
}