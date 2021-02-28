#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    vector <pair<int,int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(),a.end());

    for(int i = 0; i < n; i++){

        cout << a[i].first << ' ' <<a[i].second << '\n';
    }

}