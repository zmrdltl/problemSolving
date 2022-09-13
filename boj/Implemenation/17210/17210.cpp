#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
int way;
int main(){
    cin >> n >> way;
    if(n > 5) {
        cout << "Love is open door";
    }
    else {
        for(int i = 1; i < n; i++){
            way = 1 - way;
            cout << way << '\n';
        }
    }
}