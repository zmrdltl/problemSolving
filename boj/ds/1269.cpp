#include <bits/stdc++.h>
using namespace std;
map <int,int> m;
int aSize,bSize, ans;
int a[200001];
int b[200001];
int main(){
    cin >> aSize >> bSize;
    for(int i = 0; i < aSize; i++) cin >> a[i];
    for(int i = 0; i < bSize; i++) cin >> b[i];

    for(int i = 0; i < aSize; i++) m[a[i]]++;
    for(int i = 0; i < bSize; i++) if(m[b[i]]) ans++;

    cout << aSize + bSize - ans * 2 <<'\n';
}