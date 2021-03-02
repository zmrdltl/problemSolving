#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
int schedule[101], multiTap[101];

int main(void){
    cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> schedule[i];
    for (int i = 0; i < k; i++){
        bool isPlugged = false; //해당 기기가 꽂혀있는지 확인

        //꽂혀있으면 continue;
        for (int j = 0; j < n; j++){
            if (multiTap[j] == schedule[i]){ 
                isPlugged = true;
                break;
            }
        }
        if (isPlugged) continue;
        
        //꽂혀있지 않다면 빈 구멍에 꽂기
        for (int j = 0; j < n; j++){
            if (!multiTap[j]){
                multiTap[j] = schedule[i];
                isPlugged = true;
                break;
            }
        }
        if (isPlugged) continue;

        //가장 나중에 다시 사용되거나 앞으로 사용되지 않는 기기 찾는다.
        int idx, deviceIdx = -1;

        for (int j = 0; j < n; j++){
            int lastUsedIdx= 0;
            int next = i + 1;
            //앞으로 사용되지 않는 기기는 lastUsedIdx가 가장 크게 되므로 제일 먼저 빠지게 됨.
            //앞으로 사용되는 기기들 중 가장 나중에 쓰이는 기기의 lastUsedIdx를 찾게됨.
            while(next < k && multiTap[j] != schedule[next]){
                lastUsedIdx++;
                next++;
            }
            
            if (lastUsedIdx > deviceIdx){
                idx = j;
                deviceIdx = lastUsedIdx;
            }
        }

        ans++;
        //가장 나중에 쓰이는 것을 빼주고 현재 멀티탭 꽂음
        multiTap[idx] = schedule[i];

    }
    cout << ans << "\n";
}


