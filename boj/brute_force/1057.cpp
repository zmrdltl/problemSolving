#include <bits/stdc++.h>
using namespace std;
int num[100001];
int main(){
    int n, a, b;
    cin >> n >> a >> b;
    int round = 0;
    while(1){
        round++;
        if(a == 1 && b == 2 || a == b){
            if(a == b) round--;
            break;  
        } 
        if(a % 2 == 1)a = a/2 + 1;
        else a /= 2;
        if(b % 2 == 1) b = b/2 + 1;
        else  b /= 2;
    }
    cout << round <<'\n';

}