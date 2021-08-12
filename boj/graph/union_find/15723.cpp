#include <bits/stdc++.h>
using namespace std;
int n, m, ck[26];
vector <int> graph[26];

int bfs(int start, int end){
    queue <int> q;
    q.push(start);
    ck[start] = 1;
    memset(ck,0,sizeof(ck));

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto next : graph[x]){
            if(ck[next]) continue;
            ck[next] = 1;
            q.push(next);
        }
    }
    return ck[end];
}

int main(){
    cin >> n;
    cin.ignore();
    while(n--){
        char x,y;
        string s;
        getline(cin,s);
        x = s[0];
        y = s[s.size() - 1];
        graph[x-'a'].push_back(y-'a');
    }
    cin >> m;
    cin.ignore();
    while(m--){
        char x,y;
        string s;
        getline(cin,s);
        x = s[0];
        y = s[s.size() - 1];
        if(bfs(x-'a',y-'a')) cout << "T\n";
        else cout << "F\n";
    }
}