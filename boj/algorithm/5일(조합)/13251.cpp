#include <bits/stdc++.h>
using namespace std;
double m, k, stonePerColor[51], pro[51], totalStone, ans;
int main(){
    cin >> m;
    for(int i = 0; i < m; i++) cin >> stonePerColor[i], totalStone += stonePerColor[i];
    cin >> k;
    int cnt = 0;

    for(int i = 0; i < m; i++){
        if(stonePerColor[i] < k) continue;
        double tmp = 1.0;
        for(int j = 0; j < k; j++) tmp *= (stonePerColor[i] - j) / (totalStone - j);
        pro[i] = tmp;
    }

    for(int i = 0; i < m; i++) ans += pro[i];
    printf("%.16f",ans);
}