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
    for(auto s = ckSet.begin(); s != ckSet.end(); s++){
        vector <int> tmp = *s;
        int x = tmp[0];
        int y = tmp[1];
        int cat = tmp[2];
        //����̶��
        if(!cat) {
            //�ٴ� ��, ���� �� �� �� �Ǵ� �ٸ� ��� ���� �־����
            if(y == 0 || ckSet.find({x,y-1,0}) != ckSet.end() || ckSet.find({x-1,y,1}) != ckSet.end() || ckSet.find({x,y,1}) != ckSet.end()) continue;
            else return false;
            
        }
        //�����
        else{
            //���� �� �κ��� ��� ���� �ְų� ���� ���� �ٸ� ���� ���ÿ� ����Ǿ� �־����

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
    //vector<int> ck(build_frame.size(),0);

    for(int i = 0; i < build_frame.size(); i++){
        int col = build_frame[i][0];
        int row = build_frame[i][1];
        int cat = build_frame[i][2];
        int install = build_frame[i][3];

        //��ġ
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


    for(auto a : answer) cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
    return answer;
}