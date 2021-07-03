#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string stringN = to_string(n);
        string stringSquare = to_string(n*n);
        if(stringSquare.find(stringN) == stringSquare.size() - stringN.size()) cout << "YES\n";
        else cout << "NO\n";
    }
}