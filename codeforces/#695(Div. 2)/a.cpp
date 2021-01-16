#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pii = pair<int,int>
using namespace std;

ll t;
char panel[200001];
int main(){
    cin >> t;
    while(t--){
        ll cnt = 7;
        ll ans = 9;
        int length;
        memset(panel,0,sizeof(panel));

        cin >> length;
        panel[0] = '9';
        panel[1] = '8';
        ll x = 1;
        ll pivot = 8;
        for(int y = 2; y < length; y++){
            ll second = abs(x-y);
            ll move = (pivot+second)%10;
            panel[y] = move+'0';
        }
        for(int i = 0; i < length; i++){
            cout << panel[i];
        }
        cout << '\n';
    }
}