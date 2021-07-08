#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n;
int ck[1000001];

void makePrime(){
    for(int i = 2; i*i <= 1000000; i++){
        if(!ck[i]){
            for(int j = i + i; j <= 1000000; j += i){
                ck[j] = 1;
            }
        }
    }
}

int main(){
    fastio;
    makePrime();

    while(1){
        cin >> n;
        if(!n) break;
        int a = 0,b = 0;
        for(int i = 2; i <= n; i++){
            if(!ck[i] && !ck[n-i]){
                printf("%d = %d + %d\n", n,i,n-i);
                break;
            }
        }
    }
}