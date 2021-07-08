#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    int cnt = 2;
    while(n > 1){
        int ret = n % cnt;
        if(ret) while((n % cnt)) cnt++;
        n /= cnt;
        cout << cnt << '\n';
    }
}