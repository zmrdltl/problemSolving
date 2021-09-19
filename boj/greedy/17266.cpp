#include <bits/stdc++.h>
using namespace std;
int n, m, lamp[100001];

int binarySearch(){
    int l = 0;
    int r = 100000;
    while(l <= r){
        int mid = (l + r) / 2;
        int flag = 0;
        if(lamp[0] > mid) flag = 1;
        for(int i = 0; i < m - 1; i++){
            if(lamp[i+1] - lamp[i] > mid * 2) { flag = 1; break; }
        }
        if(n - lamp[m-1] > mid) flag = 1;
        
        if(!flag) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> lamp[i];
    cout << binarySearch();
}