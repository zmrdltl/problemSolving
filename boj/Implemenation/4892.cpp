#include <bits/stdc++.h>
using namespace std;
int testNum, n0, n1, n2, n3, n4;
int main(){
    while(1){
        testNum++;
        string evenString = "odd";
        cin >> n0;
        if(!n0) break;
        n1 = n0 * 3;
        if(n1 % 2 == 0) evenString = "even", n2 = n1/2;
        else n2 = (n1+1)/2;
        n3 = 3 * n2;
        n4 = n3 / 9;
        cout << testNum << ". " << evenString << ' ' << n4 << '\n';
    }
}