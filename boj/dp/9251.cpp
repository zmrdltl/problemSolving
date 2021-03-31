#include <bits/stdc++.h>
using namespace std;
string a,b;
int d[1001][1001],i,j;
int main(){
    cin >> a >> b;
    for(i = 0; i < a.size(); i++){
        for(j = 0; j < b.size(); j++){
            if(a[i] == b[j]) d[i+1][j+1] = d[i][j] + 1;
            else d[i+1][j+1] = max(d[i][j+1],d[i+1][j]);
        }  
    }
    cout << d[i][j];
}
