#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Drinking { ll l, r; };
vector <Drinking> participants;
ll totalDrink, n, sum, maxi,mini = 0x3f3f3f3f;

//모두 S이하만큼 받으면서 알맞게 T의 술인것
ll binarySearch(){
    ll l = mini;
    ll r = maxi;
    ll ans = 0x3f3f3f3f;
    int cnt = 0;

    while(l<=r){
        ll mid = (l + r) / 2;
        int state = 0;
        sum = 0;
        cnt = 0;
        for(int i = 0; i < n; i++){
            //하한선이 r이라면 r을 sum에 더함
            if(mid > participants[i].r) cnt++,sum += participants[i].r;
            else {
                //상한선이 l이라면 l을 sum에 더함
                if(mid >= participants[i].l)
                    cnt++,sum += mid;
            }
        }
        if(cnt < n) { l = mid + 1; continue; } 
        if(sum < totalDrink) l = mid + 1;
        else if (sum == totalDrink) return mid;
        else r = mid - 1;
    }
    if(l > totalDrink) return -1;
    return l;
}

bool operator < (const Drinking &a, const Drinking &b){
    if(a.l == b.l) return a.r < b.r;
    return a.l < b.l;
}

int main(){
    cin >> n >> totalDrink;
    participants.resize(n);
    for(int i = 0; i < n; i++){
        cin >> participants[i].l >> participants[i].r;
        sum += participants[i].r;
        maxi = max(maxi, participants[i].r);
        mini = min(mini, participants[i].l);
    }
    if(sum < totalDrink) { cout << -1; return 0; }
    sort(participants.begin(),participants.end());

    cout << binarySearch() <<'\n';
}