#include <bits/stdc++.h>
using namespace std;
int n, m, query[21][21];
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> query[i][j];
    if(n >= 8) cout << "satisfactory";
    else cout << "unsatisfactory";
}