#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> d;
int main(){
    while(cin >> n){
        d.resize(n,0);
        int length = 0;
        for (int i = 0; i < n; i++){
            int value;
            cin >> value;
            auto p = lower_bound(d.begin(), d.begin() + length, value);
            *p = value;
            if (p == d.begin() + length) length++;
        }
        cout << length << "\n";
    }
}
