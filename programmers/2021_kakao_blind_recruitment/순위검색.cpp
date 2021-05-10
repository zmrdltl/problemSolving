#include <bits/stdc++.h>
using namespace std;

vector <string> split(string input, char delimiter){
    vector <string> result;
    stringstream ss(input);
    string tmp;

    while(getline(ss,tmp,delimiter)) result.push_back(tmp);
    return result;
}

int getLanguageNum(string data){
    if(data == "cpp") return 0;
    if(data == "java") return 1;
    if(data == "python") return 2;
    return 3;
}

int getJobNum(string data){
    if(data == "backend") return 0;
    if(data == "frontend") return 1;
    return 2;
}

int getCareerNum(string data){
    if(data == "junior") return 0;
    if(data == "senior") return 1;
    return 2;
}

int getSoulFoodNum(string data){
    if(data == "chicken") return 0;
    if(data == "pizza") return 1;
    return 2;
}

void sortAll(vector <int> d[3][2][2][2]){
    for(int l = 0; l < 3; l++){
        for(int j = 0; j < 2; j++){
            for(int c = 0; c < 2; c++){
                for(int s = 0; s < 2; s++){
                    sort(d[l][j][c][s].begin(),d[l][j][c][s].end());
                }
            }
        }
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    //언어, 지원 직군, 경력구분, 소울푸드
    vector <int> d[3][2][2][2];
    for(int i = 0; i < info.size(); i++){
        vector <string> splitedInfo = split(info[i], ' ');
        int languageNum = getLanguageNum(splitedInfo[0]);
        int jobNum = getJobNum(splitedInfo[1]);
        int careerNum = getCareerNum(splitedInfo[2]);
        int soulFoodNum = getSoulFoodNum(splitedInfo[3]);
        d[languageNum][jobNum][careerNum][soulFoodNum].push_back(stoi(splitedInfo[4]));
    }

    sortAll(d);
    
    for(int i = 0; i < query.size(); i++){
        int al, bl, aj, bj, ac, bc, as, bs, cnt = 0;
        vector <string> splitedQeury = split(query[i], ' ');
        int languageNum = getLanguageNum(splitedQeury[0]);
        int jobNum = getJobNum(splitedQeury[2]);
        int careerNum = getCareerNum(splitedQeury[4]);
        int soulFoodNum = getSoulFoodNum(splitedQeury[6]);
        int score = stoi(splitedQeury[7]);
        //'-'
        if(languageNum == 3) al = 0, bl = 2;
        else al = bl = languageNum;

        if(jobNum == 2) aj = 0, bj = 1;
        else aj = bj = jobNum;

        if(careerNum == 2) ac = 0, bc = 1;
        else ac = bc = careerNum;

        if(soulFoodNum == 2) as = 0, bs = 1;
        else as = bs = soulFoodNum;

        for(int l = al; l <= bl; l++){
            for(int j = aj; j <= bj; j++){
                for(int c = ac; c <= bc; c++){
                    for(int s = as; s <= bs; s++){
                        int idx = d[l][j][c][s].size() - (lower_bound(d[l][j][c][s].begin(),d[l][j][c][s].end(),score) - d[l][j][c][s].begin());
                        cnt += idx;
                    }
                }
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}