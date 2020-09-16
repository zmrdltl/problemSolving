#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int channelToGo;
int brokenNum;
int result = 0x7f7f7f7f;

int brokenChannels[10];
vector <int> nonBrokenChannels;

void getNumberToPush(int cnt, int value, int num){
    if(cnt==num){
        result = min(result, abs(channelToGo - value) + num);
        return;
    }
    for(int i =0; i < nonBrokenChannels.size(); i++){
        getNumberToPush(cnt+1, value*10+nonBrokenChannels[i], num);
    }   
}

int main(){
    cin >> channelToGo >> brokenNum;

    for(int i = 0; i < brokenNum; i++){
        int channelNum;
        cin >> channelNum;
        brokenChannels[channelNum] = 1;
    }

    for(int i = 0; i< 10; i++){
        if(!brokenChannels[i])
            nonBrokenChannels.push_back(i);
    }

    for(int i = 1; i <= 7; i++)
        getNumberToPush(0,0,i);
    cout << min(abs(100-channelToGo),result); 
}