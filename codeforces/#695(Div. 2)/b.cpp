//TODO 
 
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pii = pair<int,int>
using namespace std;

ll t;
ll arr[300001];
int main(){
    cin >> t;

    while(t--){
        ll n;
        cin >> n;
        memset(arr,0,sizeof(arr));
        for(int i = 0; i < n; i++) cin >> arr[i];
        if(n <=3) {cout << 0 << '\n'; continue;}

        int cnt = 0;
        int cnt2 = 0;
        int flag = 0;
        int piv = 0;
        int v = 0;
        for(int i = 1; i < n-1; i++){
            if(arr[i-1] > arr[i] && arr[i] < arr[i+1]){
                if(!flag){
                    flag = 1;
                    if(arr[i-1] > arr[i+1]) {piv = i; v = arr[i+1]; arr[i] = arr[i-1];}
                    else {piv = i; v = arr[i+1];arr[i] = arr[i+1];}
                }
            }
        }
        for(int i = 1; i < n-1; i++){
            if(arr[i-1] > arr[i] && arr[i] < arr[i+1]){
                cnt++;
            }
        }
        flag = 0;
        arr[piv] = v;
        for(int i = 1; i < n-1; i++){
            if(arr[i-1] < arr[i] && arr[i] > arr[i+1]){
                if(!flag){
                    flag = 1;
                    arr[i] = min(arr[i-1],arr[i+1]);
                }
            }
        }
        for(int i = 1; i < n-1; i++){
            if(arr[i-1] < arr[i] && arr[i] > arr[i+1]){
                cnt2++;
            }
        }
        if(cnt && cnt2) cout << min(cnt,cnt2) <<'\n';
        else 
    }
}