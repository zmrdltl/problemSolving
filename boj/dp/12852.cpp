#include <bits/stdc++.h>
#define BIG 0x3f3f3f3f
using namespace std;

int d[1000001], arr[1000001];
int n;

int main(void) {
    cin >> n;
	fill(d,d+n+1,BIG);
    d[1] = 0;
    for(int i = 1; i <= n; i++){
        if(i+1 <= n && d[i+1] > d[i] + 1){
            d[i+1] = d[i] + 1;
            arr[i+1] = i;
        }

        if(i * 2 <= n && d[i*2] > d[i] + 1){
            d[i*2] = d[i] + 1;
            arr[i*2] = i;
        }

        if(i * 3 <= n && d[i*3] > d[i] + 1){
            d[i*3] = d[i] + 1;
            arr[i*3] = i;
        }
    }
    cout << d[n] << '\n';
    while(n){
        cout << n << ' ';
        n = arr[n];
    }
}