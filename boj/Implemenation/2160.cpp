#include <bits/stdc++.h>
using namespace std;
int n;
vector <vector<string>> picture;
int minPic[2];
int minPivot = 0x7f7f7f7f;

int getDifference(vector<string> a, vector<string> b){
    int cnt = 0;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[i].size(); j++){
            if(a[i][j]!=b[i][j])cnt++;
        }
    }
    return cnt;
}

int main(){
    cin >> n;
    for(int pic = 0; pic < n; pic++){
        vector <string> s;
        for(int i = 0; i < 5; i++){
            string tmp;
            cin >> tmp;
            s.push_back(tmp);
        }
        picture.push_back(s);
    }
    for(int i = 0; i < n; i ++){
        vector <string> onePic = picture[i];
        for(int j = i+1; j < n; j++){
            vector <string> secondPic = picture[j];
            int difference = getDifference(onePic,secondPic);
            if(difference < minPivot){
                minPivot = difference;
                minPic[0] = i+1;
                minPic[1] = j+1;
            }
        }
    }
    cout << minPic[0] << ' ' << minPic[1] <<'\n';
}