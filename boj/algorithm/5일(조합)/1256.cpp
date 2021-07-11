#include <bits/stdc++.h>
using namespace std;
string word;
//i개의 a와 j개의 z로 만들 수 있는 문자열의 개수
int d[101][101];

int dp(int aNum, int zNum){
    if(!aNum || !zNum) return 1;
    int &ret = d[aNum][zNum];
    if(ret != -1) return ret;
    ret = 0x3f3f3f3f;
    ret = min(ret,dp(aNum-1,zNum)+dp(aNum,zNum - 1));
    return ret;
}

void makeWord(int n, int m, int k){
    if(!n) { for(int i = 0; i < m; i++) word+='z'; return; }
    if(!m) { for(int i = 0; i < n; i++) word+='a'; return; }

    int curSequence = dp(n-1,m);
    if(k < curSequence){
        word += 'a';
        makeWord(n-1,m,k);
    }
    else{
        word+= 'z';
        makeWord(n,m-1,k-curSequence);
    }
}

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    memset(d,-1,sizeof(d));
    if(k > dp(n,m)) cout << -1;
    else makeWord(n,m,k-1), cout << word;
}