#include <bits/stdc++.h>
using namespace std;

char getDegree(double avg){
    if(avg >= 90.0) return 'A';
    if(avg >= 80.0) return 'B';
    if(avg >= 70.0) return 'C';
    if(avg >= 50.0) return 'D';
    return 'F';
}

string solution(vector<vector<int>> scores) {
    string answer = "";
    for(int i = 0; i < scores.size(); i++){
        int minScore = 0x3f3f3f3f;
        int maxScore = 0;
        int minCnt = 0;
        int maxCnt = 0;

        for(int j = 0; j < scores[i].size(); j++){
            minScore = min(minScore, scores[j][i]);
            maxScore = max(maxScore, scores[j][i]);
        }

        
        for(int j = 0; j < scores[i].size(); j++){
            if(scores[j][i] == minScore) minCnt++;
            if(scores[j][i] == maxScore) maxCnt++;
        }
        double sum = 0;
        int flag = 0;

        for(int j = 0; j < scores[i].size(); j++){
            if(j == i){
                if(scores[j][i] == minScore && minCnt == 1) { flag = 1; continue; }
                if(scores[j][i] == maxScore && maxCnt == 1) { flag = 1; continue;}
            }
            sum += scores[j][i];
        }

        double avg = sum / (scores.size() - flag);
        answer.push_back(getDegree(avg));

    }

    return answer;
}