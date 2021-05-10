#include <bits/stdc++.h>
using namespace std;

bool isOk(string friends, char a, char b, char op, int num){
    int aIdx = friends.find(a), bIdx = friends.find(b);
    if(op == '=') if(abs(aIdx-bIdx) == num+1) return true;
    if(op == '>') if(abs(aIdx-bIdx) > num+1) return true;
    if(op == '<') if(abs(aIdx-bIdx) < num+1) return true;
    return false;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    int cnt = 0;
    string friends = "ACFJMNRT";
    do{
        int flag = 0;
        for(auto d : data){
            char a = d[0];
            char b = d[2];
            char op = d[3];
            int num = d[4]-'0';
            if(!isOk(friends,a,b,op,num)) {flag = 1; break;}
        }
        if(!flag) answer++;
    }while(next_permutation(friends.begin(),friends.end()));
    return answer;
}