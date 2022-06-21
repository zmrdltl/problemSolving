#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
vector <vector<int>> info(6);

bool cmp(pii a, pii b){
  return a.second > b.second;
}

int can(){
  vector <int> loseCnt(6,0), drawCnt(6,0);
  vector <pair<int,int>> v, v2;
  for(int i = 0; i < 6; i++){
    v.push_back({i,info[i][2]});
  } 
  sort(v.begin(), v.end(), cmp);

  for(int i = 0; i < 6; i++){
    v2.push_back({i,info[i][1]});
  } 
  sort(v2.begin(), v2.end(), cmp);
  

  for(int i = 0; i < 6; i++){
    int win = info[i][0];
    for(int j = 0; j < 6; j++){
      if(i == v[j].first || info[v[j].first][2] == loseCnt[v[j].first]) continue;
      if(!win) break;
      loseCnt[v[j].first]++;
      win--;
    }
  }

  for(int i = 0; i < 6; i++){
    int draw = info[i][1];
    for(int j = 0; j < 6; j++){
      if(i == v2[j].first || info[v2[j].first][1] == drawCnt[v2[j].first]) continue;
      if(!draw) break;
      drawCnt[v2[j].first]++;
      draw--;
    }
  }

  for(int i = 0; i < 6; i++){
    if(loseCnt[i] != info[i][2] || info[i][1] != drawCnt[i]) return 0;
  }

  return 1;
}

int main(){
  for(int i = 0; i < 4; i++){

    info.clear();

    for(int k = 0; k < 6; k++){
      vector <int> countryInfo(3);
      for(int j = 0; j < 3; j++){
        cin >> countryInfo[j];
      }
      info.push_back(countryInfo);
    }

    cout << can() << '\n';
  }
}