#include <bits/stdc++.h>
using namespace std;
int oven[300001];
int doughCnt[300001];
int main(){
    int ovenCnt,doughCnt;
    cin >> ovenCnt >> doughCnt;
    for(int i = 0; i < ovenCnt; i++)
        cin >> oven[i];
    for(int i = 0; i < doughCnt; i++)
        cin >> doughCnt;
    for(int i = 0; i < ovenCnt - 1; i++)
        oven[i + 1] = min(oven[i],oven[i+1]); 
    
    //for(int i = 0; i < ovenCnt; i++) cout << oven[i] << ' ';
    int d = 0;
    int pos = ovenCnt;
    int old = 0;
    for(int i = 0; i < ovenCnt; i++){
        old = d;
        if(!pos) continue;
        if(d <= old) {pos--; continue;}
        int low = 0, mid, high = pos-1;
        while(low <= high){
            mid = (low+high) / 2;
            if(d <= oven[mid]){
                pos = mid;
                low = mid+1;
            }
            else high = mid - 1;
        }
    }
    cout << pos+1 <<'\n';
}