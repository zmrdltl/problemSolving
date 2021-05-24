#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> stones, int k) {
    int left = 1, right = *max_element(stones.begin(),stones.end());
    while(left <= right){
        int mid = (left + right) / 2;
        int cnt = 0;
        int maxCnt = 0;
        for(int i = 0; i < stones.size(); i++){
            if(stones[i] - mid <= 0) cnt++;
            else maxCnt = max(maxCnt, cnt),cnt = 0;
        }
        cnt = max(maxCnt,cnt);
        if(cnt >= k) right = mid - 1;
        else left = mid + 1;
        //cout << "l mid r cnt : " << left << ' ' << mid << ' ' << right << ' ' << cnt << '\n';
    }
    return left;
}