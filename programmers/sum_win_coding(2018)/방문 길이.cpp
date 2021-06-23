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
                if(!ck[curY+5][curX+5][0]){
                    ck[curY+5][curX+5][0] = 1;
                    ck[nextY+5][nextX+5][1] = 1;
                    answer++;
                }

            }
        }
        else if(dirs[i] == 'D'){
            if(-5 <= curY - 1 && curY - 1 <= 5){
                nextY = curY - 1;
                if(!ck[curY+5][curX+5][1]){
                    ck[curY+5][curX+5][1] = 1;
                    ck[nextY+5][nextX+5][0] = 1;
                    answer++;
                }

            }
        }

        else if(dirs[i] == 'L'){
            if(-5 <= curX - 1 && curX - 1 <= 5){
                nextX = curX - 1;
                if(!ck[curY+5][curX+5][2]){
                    ck[curY+5][curX+5][2] = 1;
                    ck[nextY+5][nextX+5][3] = 1;
                    answer++;
                }
            }
        }
        else{
            if(-5 <= curX + 1 && curX + 1 <= 5){
                nextX = curX + 1;
                if(!ck[curY+5][curX+5][3]){
                    ck[curY+5][curX+5][3] = 1;
                    ck[nextY+5][nextX+5][2] = 1;
                    answer++;
                }
            }
        }
        curX = nextX;
        curY = nextY;
    }
    return answer;
}