#include <bits/stdc++.h>
#define INF 0x3f3f3f3f;
using namespace std;
using pii = pair<int,int>;
int office[10][10];
int origin[10][10];
int ans;
int n,m;

//аб, ╩С, ©Л, го
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

struct info{
    int x,y,category,rotateNum;
};


void inputArea(int dir, int x, int y){
    while(1) {
        x += dx[dir];
        y += dy[dir];
        if(x < 0 || x >= n || y < 0 || y >=m) break;
        if(office[x][y]==6) break;
        if(office[x][y]!=0) continue; 
        office[x][y] = INF;
    }
}

void copyOffice(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            office[i][j] = origin[i][j];
        }
    }
}

int getVoidedArea(){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!office[i][j]) cnt++;
        }
    }
    return cnt;
}

int main(){
    cin >> n >> m;
    int cameraNum = 0;
    int ans = 0;
    vector<info> cameraStat(8);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            cin >> origin[i][j];
            if(!origin[i][j])ans++;
            if(origin[i][j]!=0 && origin[i][j] != 6) {
                cameraStat[cameraNum].x = i;
                cameraStat[cameraNum].y = j;
                cameraStat[cameraNum].category = origin[i][j];
                cameraStat[cameraNum].rotateNum = 0;
                cameraNum++;
            }
        }
    }
    for(int i = 0; i < (1<<(2*cameraNum)); i++ ){
        copyOffice();
        int num = i;
        for(int j = 0; j < cameraNum; j++){
            cameraStat[j].rotateNum = num % 4;
            num/=4;
            switch(cameraStat[j].category){
                case 1: 
                    inputArea((2+cameraStat[j].rotateNum)%4, cameraStat[j].x, cameraStat[j].y);
                    break;
                case 2:
                    //аб, ©Л
                    inputArea(cameraStat[j].rotateNum,cameraStat[j].x,cameraStat[j].y);
                    inputArea((2+cameraStat[j].rotateNum)%4,cameraStat[j].x,cameraStat[j].y);
                    break;
                case 3:
                    //╩С, ©Л
                    inputArea((1+cameraStat[j].rotateNum)%4,cameraStat[j].x,cameraStat[j].y);
                    inputArea((2+cameraStat[j].rotateNum)%4,cameraStat[j].x,cameraStat[j].y);
                    break;
                case 4:
                    for(int i=0;i<3;i++){
                        inputArea((i+cameraStat[j].rotateNum) %4 , cameraStat[j].x, cameraStat[j].y);
                    }
                    break;
                case 5:
                    for(int i=0;i<4;i++)
                        inputArea(i, cameraStat[j].x, cameraStat[j].y);
                    break;
            }

            ans = min(ans,getVoidedArea());
        }
    }
    cout << ans <<'\n';
}