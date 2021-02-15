#include <bits/stdc++.h>
using namespace std;
bool isPrime(int num){
    if(num <= 1) return false;
    for(int i = 2; i < num ; i++){
        if(num % i == 0) return false;
    }
    return true;
}

int dfs(int size,string num, int depth, vector<char> &c, int visitIdx[], map<int,int> &visited){
    if(depth == size){
        string tmp = "";
        for(auto s : c) tmp += s;
        int tmpNum = stoi(tmp);
        if(visited[tmpNum]) return 0;
        visited[tmpNum] = 1;
        return isPrime(tmpNum);
    }   
    
    int ans = 0;
    for(int i = 0; i < num.size(); i++){
        if(!visitIdx[i]){
            visitIdx[i] = 1;
            c.push_back(num[i]);
            ans += dfs(size,num,depth+1,c,visitIdx,visited);
            c.pop_back();
            visitIdx[i] = 0;
        }
    }   
    return ans;
}

int solution(string num) {
    vector <char> c;
    int visitIdx[100];
    map<int,int> visited;
    memset(visitIdx,0,sizeof(visitIdx));
    int ans = 0;
    for(int i = 1; i <= num.size(); i++)
        ans+=dfs(i,num,0,c,visitIdx,visited);
    return ans;
}

int main(){
    cout << solution("00011");
}