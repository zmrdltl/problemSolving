#include <bits/stdc++.h>
using namespace std;
vector<double> winRate;
vector<int> winCnt, player, weight;

bool cmp(int a, int b){
    if(winRate[a-1] == winRate[b-1]){
        if(winCnt[a-1] == winCnt[b-1]) {
            if(weight[a-1] == weight[b-1]) return a < b;
            return weight[a-1] > weight[b-1];
        }
        return winCnt[a-1] > winCnt[b-1];
    }
    return winRate[a-1] > winRate[b-1];
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
    winRate.resize(weights.size());
    winCnt.resize(weights.size());
    player.clear();
    weight = weights;

    for(int i = 0; i < weights.size(); i++) player.push_back(i+1);
    for(int i = 0; i < head2head.size(); i++){
        double win = 0;
        double totalGame = 0;
        int winHeavy = 0;
        for(int j = 0; j < head2head[i].size(); j++){
            if(i == j) continue;
            if(head2head[i][j] != 'N') totalGame++;
            if(head2head[i][j] == 'W') {
                win++;
                if(weights[i] < weights[j]) winHeavy++;
            }
        }
        if(totalGame == 0) winRate[i] = 0;
        else winRate[i] = win / totalGame * 100;
        winCnt[i] = winHeavy;
    }
    
    sort(player.begin(), player.end(), cmp);
    return player;
}