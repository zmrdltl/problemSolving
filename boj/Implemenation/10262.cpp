#include <bits/stdc++.h>
using namespace std;
int gunnar[4], emma[4], g[2], e[2], gWin, eWin;
int main(){
    for(int i = 0; i < 4; i++) cin >> gunnar[i];
    for(int i = 0; i < 4; i++) cin >> emma[i];
    g[0] = gunnar[0] + gunnar[1];
    g[1] = gunnar[2] + gunnar[3];
    e[0] = emma[0] + emma[1];
    e[1] = emma[2] + emma[3];
    if(g[0] - e[0] + g[1] - e[1] == 0) cout << "Tie";
    else if(g[0] - e[0] + g[1] - e[1] > 0) cout << "Gunnar";
    else cout << "Emma";
}