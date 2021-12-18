#include <bits/stdc++.h>
using namespace std;

vector <string> getAnsString(int ansHour, int ansMinute){
    vector <string> tmp(2,"");
    if(ansHour < 10) tmp[0] += '0';
    tmp[0] += to_string(ansHour);
    if(ansMinute < 10) tmp[1] += '0';
    tmp[1] += to_string(ansMinute);
    return tmp;
}

int main(){
    while(1){
        int sh, sm, eh, em, tot = 0, plusDay = 0;
        scanf("%d:%d %d:%d", &sh, &sm, &eh, &em);
        if(!sh && !sm && !eh && !em) break;
        tot = sh * 60 + sm + eh * 60 + em;
        plusDay = tot / 60 / 24;
        vector <string> ans = getAnsString(tot / 60 % 24, tot % 60);
        if(plusDay) cout << ans[0] << ':' << ans[1] << ' ' << "+" << plusDay;
        else cout << ans[0] << ':' << ans[1];
        cout << '\n';
    }
}