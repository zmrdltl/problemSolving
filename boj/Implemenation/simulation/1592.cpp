#include <bits/stdc++.h>
using namespace std;
int n,m,l;
int throwCnt, cur;
int ballCnt[1001];

int main(){
    cin >> n >> m >> l;
    ballCnt[cur] = 1;
    while(ballCnt[cur] != m){
        if(ballCnt[cur] % 2) cur = (cur+l) % n;
        else cur = (n+(cur-l)) % n;
        ballCnt[cur]++;
        throwCnt++;
    }
    cout << throwCnt <<'\n';
}