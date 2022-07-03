#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    for(int i = 0; i < n/4; i++){
        cout << "long ";
        if(i == n/4 - 1) cout << "int";
    }
}