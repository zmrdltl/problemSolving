#include <bits/stdc++.h>
using namespace std;
int a,b,c,ans=0;
int t[101];
int main(){
    cin >> a >> b >> c;
    for(int i = 0; i < 3; i++){
        int s,e;
        cin >> s >> e;
        for(int j = s; j < e; j++) t[j]++;
    }
    for(int i = 1; i <= 100; i++){
        if(t[i]==1) ans+= t[i] * a;
        else if(t[i]==2) ans+= t[i] * b;
        else ans+= t[i] * c;
    }
    cout << ans <<'\n';
}   
