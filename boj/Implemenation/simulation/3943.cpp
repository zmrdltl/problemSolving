#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, t;
int main(){
    fastio;
    cin >> t;
    while(t--){
        cin >> n;
        int big = n;
        while(n != 1){
            int num;
            if(n%2) num = n*3 + 1;
            else num = n/2;
            n = num;
            big = max(big,num);
        }
        cout << big << '\n';
    }

}