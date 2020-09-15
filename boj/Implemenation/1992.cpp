#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int n;
int video[64][64];
string tmpVideo[64];
string ans;
bool haveToBePressed(int i,int j, int width){
    int pivot = video[i][j];
    for(int x = i; x < i + width; x++){
        for(int y = j; y < j + width; y++){
            if(pivot!=video[x][y]) return 1; //통일되어 있지 않은 영상영역은 압축해야함
        }
    }
    return 0;
}

void pressVideo(int i, int j,int width){
    if(haveToBePressed(i,j,width)){
        ans += '(';
        pressVideo(i,j,width/2);
        pressVideo(i,j+width/2,width/2);
        pressVideo(i+width/2,j,width/2);
        pressVideo(i+width/2,j+width/2,width/2);
        ans += ')';
    }else{
        if(video[i][j]==0) ans+='0';
        else ans += '1';
        return;
    }
    return;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> tmpVideo[i];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j ++){
            video[i][j] = tmpVideo[i][j] - '0';
        }
    }
    pressVideo(0,0,n);
    cout << ans <<'\n';
}