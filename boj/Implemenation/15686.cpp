#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct chickenInfo{
    int x,y,isClosed = 0;
};

struct homeInfo{
    int x,y;
};

int calCulateDistance(int x1, int x2, int y1, int y2){
    return abs(x1-x2) + abs(y1-y2);
}

int getMinChickenDistance(vector <chickenInfo> chickenCoord,
    vector <homeInfo> homeCoord){
    int distance = 0;
    for(int i = 0; i < homeCoord.size(); i++){
        int tmp = 101;
        for(int j = 0; j < chickenCoord.size(); j++){
            if(chickenCoord[j].isClosed){
                int x1 = homeCoord[i].x;
                int x2 = chickenCoord[j].x;
                int y1 = homeCoord[i].y;
                int y2 = chickenCoord[j].y;
                tmp = min(tmp,calCulateDistance(x1,x2,y1,y2));
            }
        }
        distance += tmp;
    }
    return distance;
}


int main(){
    int n,m;
    int map[51][51];
    int ret = 101 * 101;
    vector <chickenInfo> chickenCoord;
    vector <homeInfo> homeCoord;
    cin >> n >> m;
    for(int i  =0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
            if(map[i][j]==2){
                chickenCoord.push_back({i,j,0});
            }else if(map[i][j]==1){
                homeCoord.push_back({i,j});
            }
        }
    }
    
    for(int i = 0; i < (1<<chickenCoord.size()); i++){
        int cnt =0;
        int tmp  = i;
        for(int i = 0; i < chickenCoord.size(); i++) 
            chickenCoord[i].isClosed = 0;

        while(tmp){
            cnt += tmp %2;
            tmp/=2;
        }
        if(cnt > m) continue;

        for(int j=0;j<chickenCoord.size();j++) chickenCoord[j].isClosed = (i & (1<<j));  
        ret = min(ret,getMinChickenDistance(chickenCoord,homeCoord));
    }
    cout << ret << '\n';
}   