#include <bits/stdc++.h>
using namespace std;
int n, ans;
int getClapNum(int num){
    int cnt = 0, tmp = num;
    while(tmp){
        if(tmp%10 == 3 || tmp%10 == 6 || tmp%10 == 9) cnt++;
        tmp/=10;
    }
    return cnt;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) ans += getClapNum(i);
    cout << ans;
}