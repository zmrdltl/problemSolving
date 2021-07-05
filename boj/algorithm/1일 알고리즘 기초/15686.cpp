#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n,m;
int city[51][51];
int ans = 0x3f3f3f3f;
struct home { int x,y; };
struct chicken { int x,y,opened; };

vector <home> homes;
vector <chicken> chickens;

int getDistance(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}

int getChickDist(){
    int dist = 0;
    for(int i = 0; i < homes.size(); i++){
        int tmp = 101;
        for(int j = 0; j < chickens.size(); j++){
            if(chickens[j].opened){
                int x1 = homes[i].x;
                int y1 = homes[i].y;
                int x2 = chickens[j].x;
                int y2 = chickens[j].y;
                tmp = min(tmp, getDistance(x1,y1,x2,y2));
            }
        }
        dist += tmp;
    }
    return dist;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> city[i][j];
            if(city[i][j] == 1) homes.push_back({i,j});
            else if(city[i][j] == 2) chickens.push_back({i,j,0});
        }
    }

    for(int i = 0; i < (1 << chickens.size()); i++){
        int chickenStat = 0;
        int tmp = i;
        while(tmp){
            chickenStat += tmp % 2;
            tmp/= 2;
        }
        if(chickenStat > m) continue;
        for(int j = 0; j < chickens.size(); j++){
            chickens[j].opened = i & (1<<j);
        }
        ans = min(ans,getChickDist());
    }
    cout << ans;
}