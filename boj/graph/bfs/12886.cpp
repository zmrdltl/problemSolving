#include <bits/stdc++.h>
using namespace std;
int ck[2001][2001];
int bfs(int a,int b, int c){
    queue <tuple<int,int,int>> q;
    q.push({a,b,c});
    ck[a][b] = 1;
    ck[b][a] = 1;
    ck[a][c] = 1;
    ck[c][a] = 1;
    ck[b][c] = 1;
    ck[c][b] = 1;
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();
        if(x == y && y == z) return 1;
        if(y - x > 0 && !ck[x+x][y-x]){
            q.push({x+x,y-x,z});
            ck[x+x][y-x] = 1;
        }
        if(x - y > 0 && !ck[x-y][y+y]){
            q.push({x-y,y+y,z});
            ck[x-y][y+y] = 1;
        }
        if(z - x > 0 && !ck[x+x][z-x]){
            q.push({x+x,y,z-x});
            ck[x+x][z-x] = 1;
        }
        if(x - z > 0 && !ck[x-z][z+z]){
            ck[x-z][z+z] = 1;
            q.push({x-z,y,z+z});
        }
        if(z - y > 0 && !ck[y+y][z-y]){
            ck[y+y][z-y] = 1;
            q.push({x,y+y,z-y});
        }
        if(y - z > 0 && !ck[y-z][z+z]){
            ck[y-z][z+z] = 1;
            q.push({x,y-z,z+z});
        }
    }
    return 0;
}

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << bfs(a,b,c);
}