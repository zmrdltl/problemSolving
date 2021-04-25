#include <bits/stdc++.h>
using namespace std;
int n,m,j, ans;
int main(){
    cin >> n >> m >> j;
    int left = 1,right = m;
    while(j--){
        int pos;
        cin >> pos;
        while(left > pos || right < pos){
            if(pos > right) right++, ans++, left++;
            if(pos < left) right--,ans++,left--;
        }
    }
    cout << ans << '\n';   
}