#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int a,b;
int ck[10001];
int ansSize,testCase;

int D(int num){
    if(num * 2 > 9999) return (num*2) % 10000;
    return num * 2;
}

int S(int num){
    if(num - 1 < 0) return 9999;
    return num - 1;
}

int L(int num){
    return (num % 1000) * 10 + num / 1000;
}

int R(int num){
    return (num % 10) * 1000 + (num / 10);
}

string bfs(){
    queue <pair<string,int>> q;
    q.push({"",a});
    while(!q.empty()){
        string op = q.front().first;
        int nextNum = q.front().second;

        if(nextNum==b) return op;
        q.pop();

        if(!ck[D(nextNum)]){
            q.push({op+"D",D(nextNum)});
            ck[D(nextNum)] = 1;
        }

        if(!ck[S(nextNum)]){
            q.push({op+"S",S(nextNum)});
            ck[S(nextNum)] = 1;
        }
            
        if(!ck[L(nextNum)]){
            q.push({op+"L",L(nextNum)});
            ck[L(nextNum)] = 1;
        }

        if(!ck[R(nextNum)]){
            q.push({op+"R",R(nextNum)});
            ck[R(nextNum)] = 1;
        }
    }
    
}

int main(){
    fastio;
    cin >> testCase;
    while(testCase--){
        memset(ck,0,sizeof(ck));
        ansSize = 0x7f7f7f7f;
        cin >> a >> b;
        cout << bfs() << '\n';
    }
}
