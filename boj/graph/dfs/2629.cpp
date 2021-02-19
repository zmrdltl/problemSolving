#include <bits/stdc++.h>
using namespace std;
int choo[31];
bool can[31][40001];
int chooNum, bidNum;

void dfs(int cnt, int weight){
    if(cnt > chooNum) return;
    if(can[cnt][weight]) return;
    can[cnt][weight] = 1;
    dfs(cnt +1, weight+choo[cnt]);
    dfs(cnt +1, weight);
    dfs(cnt +1, abs(weight-choo[cnt]));
}

int main(){
    cin >> chooNum;
    for(int i = 0; i < chooNum; i++) cin >> choo[i];
    cin >> bidNum;
    dfs(0,0);

    for(int i = 0; i < bidNum; i++) {
        int bidWeight;
        cin >> bidWeight;
        int flag = 0;
        for(int i = 0; i <= chooNum; i++){
            if(can[i][bidWeight]){
                flag = 1;
                break;
            }
        }
        if(flag) cout << "Y ";
        else cout << "N ";
    }

}