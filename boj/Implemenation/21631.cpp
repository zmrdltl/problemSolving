#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll white, black;
int main(){
    cin >> white >> black;
    if(white >= black) cout << black;
    else cout << white + 1;
}