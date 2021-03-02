#include <bits/stdc++.h>
using namespace std;

void primeInit(int ck[]){
    for(int i = 2 ; i <= 1000000; i++){
        if(ck[i]) continue;
        for(int j = i+i; j <= 1000000; j+=i){
            ck[j] = 1;
        }
    }
}

int solution(int n) {
    int answer = 0;
    int ck[1000001];
    memset(ck,0,sizeof(ck));
    primeInit(ck);
    for(int i= 2; i <= n; i++) if(!ck[i]) answer++;
    return answer;
}