#include <bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        int n, sum = 0, cnt = 1;
        cin >> n;
        if(!n) break;
        for(int i = 0; i < n; i++, cnt+=2) sum += cnt;
        cout << n << " => " << sum - n + 1 << '\n';
    }
}