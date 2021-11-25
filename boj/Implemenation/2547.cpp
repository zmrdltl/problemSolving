#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t;
int main(){
    cin >> t;
    while(t--){
        ll student, totalCandy = 0, candy;
        cin >> student;
        for(int i = 0; i < student; i++) {
            cin >> candy;
            totalCandy = (totalCandy + candy) % student;
        }
        if(totalCandy % student) cout << "NO\n";
        else cout << "YES\n";
    }
}