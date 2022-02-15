#include <bits/stdc++.h>
using namespace std;
int t, num;
vector <int> v;

int main(){
    cin >> t;
    for(int i = 1; i <= t; i++){
        v.clear();
        cin >> num;
        for(int j = 0, x; j < num; j++){
            cin >> x;
            if(x < 6) v.push_back(x + 1);
        }
        printf("Case %d:\n", i);
        for(auto d : v) cout << d << '\n';
    }
}