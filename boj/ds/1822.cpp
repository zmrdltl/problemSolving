#include <bits/stdc++.h>
using namespace std;
int a[500001], b[500001], aSize, bSize;
map <int,int> m;
vector <int> notInB;

int main(){
    cin >> aSize >> bSize;
    for(int i = 0; i < aSize; i++) cin >> a[i];
    for(int i = 0; i < bSize; i++) cin >> b[i];

    for(int i = 0; i < bSize; i++) m[b[i]]++;
    for(int i = 0; i < aSize; i++){
        if(!m[a[i]]) notInB.push_back(a[i]);
    }

    sort(notInB.begin(),notInB.end());
    cout << notInB.size() <<'\n';
    for(auto p : notInB) cout << p << ' ';
}