#include <bits/stdc++.h>
using namespace std;
int logs;
int main(){
    while(1){
        cin >> logs;
        int ans = 0;
        if(logs == -1) break;
        int speedPerHour[logs], totalDriveTime[logs];
        for(int i = 0; i < logs; i++) {
            cin >> speedPerHour[i] >> totalDriveTime[i];
        }
        for(int i = 0; i < logs; i++) {
            if(!i) ans += totalDriveTime[i] * speedPerHour[i];
            else ans += speedPerHour[i] * (totalDriveTime[i] - totalDriveTime[i-1]);
        }
        cout << ans << " miles\n";
    }

}