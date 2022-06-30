#include <bits/stdc++.h>
using namespace std;
using tiii = tuple<int,int,int>;
int a[3], ck[201][201][201];
vector <int> v;

void bfs(){
    queue <tiii> q;
    q.push({0,0,a[2]});

    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();
        if(ck[x][y][z]) continue;
        ck[x][y][z] = 1;
        if(!x) v.push_back(z);

        if(x + y > a[1]) q.push({x -(a[1] - y), a[1], z});
        else q.push({0, x + y, z});

        if(x + z > a[2]) q.push({x-(a[2] - z), y, a[2]});
        else q.push({0, y, x+z});

        if(y + x > a[0]) q.push({a[0],y-(a[0]-x),z});
        else q.push({y+x, 0, z});

        if(y + z > a[2]) q.push({x,y-(a[2]-z),a[2]});
        else q.push({x, 0, y+z});
        
        if(z + x > a[0]) q.push({a[0],y, z - (a[0]-x)});
        else q.push({z+x,y,0});

        if(z + y > a[1]) q.push({x, a[1],z - (a[1] - y)});
        else q.push({x, z+y, 0});
    }
}

int main(){
    for(int i = 0; i < 3; i++) cin >> a[i];
    bfs();
    sort(v.begin(), v.end());
    for(auto e : v) cout << e << ' ';
}