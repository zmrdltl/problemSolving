// d[i][j] = i번째 계단을 j번 연속으로 올라갈 때 최대값
// d[i][1] => 1번 연속으로 올라갔으므로 i-2번째 계단은 올라가거나 건너뛰거나 상관없습니다. 따라서 다음 점화식을 따릅니다.
// d[i][1] = max(d[i-2][1], d[i-2][2]) + stair[i] 
// d[i][2] => 2번 연속으로 올라갔으므로 거꾸로 생각했을 때 i-2번째 계단은 올라갔으면 안되므로.
// d[i][2] = d[i-1][1] + stair[i] 입니다.
#include <bits/stdc++.h>
using namespace std;
int stair[301];
int d[301][3];
int n;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> stair[i];
    d[1][1] = stair[1];
    for(int i = 2; i <= n; i++){
        d[i][1] = max(d[i-2][1],d[i-2][2]) + stair[i];
        d[i][2] = d[i-1][1] + stair[i];
    }
    cout << max(d[n][1],d[n][2]);
}
