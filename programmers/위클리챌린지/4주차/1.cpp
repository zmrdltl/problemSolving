//위클리 4주차
#include <bits/stdc++.h>
using namespace std;

vector <string> split(string input, char delimiter){
    vector <string> result;
    stringstream ss(input);
    string tmp;

    while(getline(ss,tmp,delimiter)) result.push_back(tmp);
    return result;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    map<string, map<string,int>> tableMap;

    for(auto t : table){
        vector <string> jobAndLanguage = split(t ,' ');
        string job = jobAndLanguage[0];

        map<string,int> tmpMap;

        for(int i = 1; i < jobAndLanguage.size(); i++){
            string language = jobAndLanguage[i];
            int score = 5 - i + 1;
            tmpMap[language] = score;
        } 
        tableMap[job] = tmpMap;
    }

    map<string,int> scoreMap;
    int maxScore = 0;
    for(auto tm: tableMap){
        int score = 0;
        string job = tm.first;
        map<string,int> scorePerLanguage = tm.second;
        for(int i = 0; i < languages.size(); i++){
            score += preference[i] * scorePerLanguage[languages[i]];
        }
        maxScore = max(maxScore,score);
        scoreMap[job] = score;
    }

    for(auto el : scoreMap){
        if(el.second == maxScore) return el.first;
    }
}