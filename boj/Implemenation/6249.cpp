#include <bits/stdc++.h>
using namespace std;
int n, p, h;
int main(){
    cin >> n >> p >> h;
    for(int i = 0, info; i < n; i++){
        cin >> info;
        if(p > info) cout << "NTV: Dollar dropped by " << p - info << " Oshloobs\n";
        if(h < info) cout << "BBTV: Dollar reached " << info << " Oshloobs, A record!\n";
        p = info, h = max(h, info);
    }
}