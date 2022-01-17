#include <bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        int n;
        cin >> n;
        if(!n) break;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                cout << "*";
            }
            cout << '\n';
        }
    }
}