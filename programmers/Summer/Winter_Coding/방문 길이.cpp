#include <bits/stdc++.h>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    //╩С,го,аб,©Л
    int ck[11][11][4];
    memset(ck,0,sizeof(ck));
    int curX = 0,curY = 0, nextX = 0, nextY = 0;

    for(int i = 0; i < dirs.size(); i++){
        if(dirs[i] == 'U'){
            if(-5 <= curY + 1 && curY + 1 <= 5){
                nextY = curY + 1;
                if(!ck[curY][curX][0]){
                    ck[curY][curX][0] = 1;
                    ck[nextY][nextX][1] = 1;
                    answer++;
                }

            }
        }
        else if(dirs[i] == 'D'){
            if(-5 <= curY - 1 && curY - 1 <= 5){
                nextY = curY - 1;
                if(!ck[curY][curX][1]){
                    ck[curY][curX][1] = 1;
                    ck[nextY][nextX][0] = 1;
                    answer++;
                }

            }
        }

        else if(dirs[i] == 'L'){
            if(-5 <= curX - 1 && curX - 1 <= 5){

                nextX = curX - 1;
                if(!ck[curY][curX][2]){
                    ck[curY][curX][2] = 1;
                    ck[nextY][nextX][3] = 1;
                    answer++;
                }
            }
        }
        else{
            if(-5 <= curX + 1 && curX + 1 <= 5){
                nextX = curX + 1;
                if(!ck[curY][curX][3]){
                    ck[curY][curX][3] = 1;
                    ck[nextY][nextX][2] = 1;
                    answer++;
                }
            }
        }
        curX = nextX;
        curY = nextY;
        cout << curX << ' ' << curY << ' ' << answer<<'\n';
    }
    return answer;
}