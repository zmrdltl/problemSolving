#include <bits/stdc++.h>
using namespace std;
int n,m,k;
string word;
//i개의 a와 y개의 z로 만들 수 있는 문자열의 개수
int d[101][101];

int dp(int i,int j){
    if(!i || !j) return 1;
    int &ret = d[i][j];
    if(ret!=-1) return ret;
    ret = min(0x3f3f3f3f, dp(i-1,j) + dp(i,j-1));
    return ret;
}

void makeWord(int x, int y, int skip){
    if(!x){
        for(int i = 0; i < y; i++) word+='z';
        return;
    }
    if(!y){
        for(int i = 0; i < x; i++) word+='a';
        return;
    }

    int curStringNum = dp(x-1,y);

    //맨앞 a붙이는 경우
    if(skip < curStringNum){
        word+='a';
        makeWord(x-1,y,skip);
    }
    //맨앞 z붙이는 경우
    else{
        word+='z';
        makeWord(x,y-1,skip-curStringNum);
    }
}

int main(){
    cin >> n >> m >> k;
    memset(d,-1,sizeof(d));

    if(k>dp(n,m)){
        cout << -1 <<'\n';
    }
    else{
        makeWord(n,m,k-1);
        cout << word <<'\n';
    }
}
