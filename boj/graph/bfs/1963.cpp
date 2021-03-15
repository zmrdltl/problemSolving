#include <bits/stdc++.h>
#define MAX 0x3f3f3f3f
using namespace std;
int t, prime[10000], ck[10000];

void makePrime(){
    for(int i = 2; i*i <= 9999; i++){
        if(!prime[i])
            for(int j = i+i; j <= 9999; j+=i) 
                prime[j] = 1;
    }
}

int bfs(string a, string b){
    queue <string> q;
    q.push(a);
    ck[stoi(a)] = 1;
    while(!q.empty()){
        string x = q.front();
        q.pop();
        if(x == b) return ck[stoi(b)] - 1;

        for(int j = 0; j < 4; j++){
            string tmp = x;
            for(int i = 0; i < 10; i++){
                if(!i && !j) continue;
                tmp[j] = i + '0';
                int newX = stoi(tmp);
                if(!ck[newX] &&!prime[newX]){
                    ck[newX] = ck[stoi(x)] + 1;
                    q.push(tmp);
                }
            }
        }
    }
    return MAX;
}

int main(){
    cin >> t;
    makePrime();
    while(t--){
        string a, b;
        memset(ck,0,sizeof(ck));
        cin >> a >> b;
        int ans = bfs(a,b);
        if(ans!=MAX) cout << ans <<'\n';
        else cout << "Impossible\n";
    }
}