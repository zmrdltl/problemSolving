#include <bits/stdc++.h>
using namespace std;
int peoplePerFloor[3], ans = 0x3f3f3f3f;
int main(){
    for(int i = 0; i < 3; i++) cin >> peoplePerFloor[i];
    for(int floor = 0; floor < 3; floor++){
        int sum = 0;
        for(int i = 0; i < 3; i++) 
            sum += abs(i - floor) * peoplePerFloor[i] * 2;
        ans = min(ans, sum);
    }
    cout << ans;
}