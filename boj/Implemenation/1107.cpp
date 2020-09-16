#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int channelToGo;
int brokenNum;
int result = 0x7f7f7f7f;

vector <int> brokenChannels;
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
        brokenChannels.push_back(channelNum);
    }

    for(int i = 0; i< 10; i++){
        int flag = 0;
        for(int j = 0; j < brokenChannels.size(); j++){
            if(brokenChannels[j]==i)
                flag = 1;
        }
        if(!flag) nonBrokenChannels.push_back(i);
    }

    for(int i = 1; i <= 7; i++)
        getNumberToPush(0,0,i);
    cout << min(abs(100-channelToGo),result); 
}