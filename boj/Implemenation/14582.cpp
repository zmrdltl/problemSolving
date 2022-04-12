#include <bits/stdc++.h>
using namespace std;
int jeminis[10], startlink[10], stat, curJScore, curSScore;
int main(){
    for(int i = 1; i <= 9; i++) cin >> jeminis[i];
    for(int i = 1; i <= 9; i++) cin >> startlink[i];
    for(int i = 1; i <= 9; i++) {
        curJScore += jeminis[i];
        if(curJScore > curSScore) stat = 1;
        curSScore += startlink[i];
        if(curJScore < curSScore && stat == 1) stat = 2;
    }
    if(stat == 2) cout << "Yes";
    else cout << "No";
}