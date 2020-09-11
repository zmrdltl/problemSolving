#include<iostream>
#include <string>
using namespace std;
//TODO 다 못함
int buttons[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
int brokenBtnNum;
int currentChannel = 100;
string channel;


int getPushNum(string x){

}

int main(){
    cin >> channel;
    cin >> brokenBtnNum;
    for(int i = 0; i < brokenBtnNum; i++){
        int idx;
        cin >> idx;
        buttons[idx] = 0;
    }
    cout << getPushNum("");
}