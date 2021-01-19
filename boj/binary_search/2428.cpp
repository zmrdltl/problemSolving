#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
double file[100001];
ll ans;

ll binarySearch(double fileSize,int idx){
    int l = 0;
    int r = idx-1;
    int cnt = 0;

    while(l <= r){
        int mid = (l + r) / 2; 
        if(file[mid] < fileSize * 0.9 ) l = mid + 1; 
        else r = mid - 1;
    }
    return idx - l;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> file[i];
    sort(file,file+n);
    for(int i = 1; i < n; i++) ans += binarySearch(file[i],i);
    cout << ans <<'\n';
}