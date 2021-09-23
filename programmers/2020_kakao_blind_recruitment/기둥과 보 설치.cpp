#include <bits/stdc++.h>
using namespace std;

bool cmp(vector <int> &a, vector <int> &b){
    if(a[0] == b[0]){
        if(a[1] == b[1]) return a[2] < b[2];
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

bool isValid(set <vector<int>> ckSet){
    for(auto s : ckSet){
        vector <int> tmp = s;
        int x = tmp[0];
        int y = tmp[1];
        int cat = tmp[2];
        //����̸� : �Ʒ� �ٴ�, �Ʒ� ���, ���� ��, ������ ���� �� ok
        if(!cat) {
            if(y == 0 || ckSet.find({x,y-1,0}) != ckSet.end() || ckSet.find({x-1,y,1}) != ckSet.end() || ckSet.find({x,y,1}) != ckSet.end()) continue;
            else return false;
        }
        //���� : �Ʒ� ���, ���� ���, (�޺��� ������) ������ �� ok
        else{
            if(ckSet.find({x,y-1,0}) != ckSet.end() || ckSet.find({x + 1, y - 1,0}) != ckSet.end() || (ckSet.find({x-1,y,1}) != ckSet.end() && ckSet.find({x+1,y,1}) != ckSet.end())) continue;
            else return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<vector<int>> board(n+1,vector<int>(n+1,0));
    set <vector<int>> ckSet;

    for(int i = 0; i < build_frame.size(); i++){
        int col = build_frame[i][0];
        int row = build_frame[i][1];
        int cat = build_frame[i][2];
        int install = build_frame[i][3];

        if(install){
            ckSet.insert({col,row,cat});
            if(!isValid(ckSet)) ckSet.erase({col,row,cat});
        }

        else{
            ckSet.erase({col,row,cat});
            if(!isValid(ckSet)) ckSet.insert({col,row,cat});
        }
    }

    for(auto c : ckSet){
        vector <int> tmp = c;
        int x = tmp[0];
        int y = tmp[1];
        int cat = tmp[2];
        answer.push_back({x, y, cat});
    }

    sort(answer.begin(),answer.end(),cmp);
    return answer;
}