#include <bits/stdc++.h>
using namespace std;
int num[1001][3];
int n;

int hasSameNum(string num){
    for(int i = 0; i < num.size(); i++)
        for(int j = i + 1; j < num.size(); j++)
            if(num[i] == num[j]) return 1;
    return 0;
}

int isZero(string num){
    for(int i = 0; i < num.size(); i++)
        if(num[i]=='0') return 1;
    return 0;
}

int getStrike(string num, string answer, int check[]){
    int strike = 0;
    for(int k = 0; k < 3; k++)
        if(num[k] == answer[k]) strike++, check[k] = 1;
    return strike;
}

int getBall(string num, string answer, int check[]){
    int ball = 0;
    for(int k = 0; k < 3; k++)
        for(int t = 0; t < 3; t++)
            if(!check[t] && !check[k] && k!=t && num[k]==answer[t])
                ball++;
    return ball;
}

int candidateNum(){
    int cnt = 0;
    for(int i = 111; i <= 999; i++){
        string answer = to_string(i);
        if(isZero(answer)) continue;
        if(hasSameNum(answer)) continue;
        int flag = 0;
        for(int j = 0; j < n; j++){
            string stringNum = to_string(num[j][0]);
            int check[3] ={0,0,0};
            int strike = getStrike(stringNum,answer,check);
            int ball = getBall(stringNum,answer,check);
            if(strike != num[j][1] || ball != num[j][2]){
                flag = 1;
                break;
            }
        }
        if(!flag) cnt++; 
    }
    return cnt;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> num[i][0] >> num[i][1] >> num[i][2];
    cout << candidateNum();
}