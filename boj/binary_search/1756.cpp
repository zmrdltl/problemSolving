#include <bits/stdc++.h>
using namespace std;
int oven[300001];
int dough[300001];

int main(){
    int ovenCnt, doughCnt;
    cin >> ovenCnt >> doughCnt;
    oven[0] = 0x7f7f7f7f;
    for(int i = 1; i <= ovenCnt; i++) cin >> oven[i];
    for(int i = 1; i <= doughCnt; i++) cin >> dough[i];
    for(int i = 1; i <= ovenCnt; i++) oven[i] = min( oven[i], oven[i-1] );
    int pos = ovenCnt+1;
    int old; 
    for(int i = 1; i <= doughCnt; i++){
        old = dough[i-1];
        if(!pos) break;
        if(dough[i] <= old){ pos--; continue; }
        int low = 0;
        int high=pos-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(dough[i] <= oven[mid]) pos = mid, low = mid+1;
            else high = mid - 1;
        }
    }
    cout << pos <<'\n';
}