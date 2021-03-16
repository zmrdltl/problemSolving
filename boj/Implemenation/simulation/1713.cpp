#include <bits/stdc++.h>
using namespace std;
int recommandStat[101]; //추천 수
int pictureStat[21]; //사진 게시 현황
int old[101]; //가장 오래된 사진
int pictureCnt, n,m;

void updateTime(){
    for(int i = 1; i <= n; i++) 
        if(pictureStat[i]) 
            old[pictureStat[i]]++;
}

void updatePictureStat(int student, int i){
    old[pictureStat[i]] = 0;
    recommandStat[pictureStat[i]] = 0;
    pictureStat[i] = student;
}

void deletePicture(int minRec, int minCnt,int student){
    //추천 이 젤 적은 학생 사진 삭제, 
    if(minCnt == 1){
        for(int i = 1; i <= n; i++){
            if(recommandStat[pictureStat[i]] == minRec){
                updatePictureStat(student,i);
            }
        }
    }
    //아니라면 가장 오래된 사진 삭제
    else{
        int oldest = 0;
        int oldestIdx = 0;
        for(int i = 1; i <= n; i++){
            int num = recommandStat[pictureStat[i]];
            if(num == minRec){
                if(oldest < old[pictureStat[i]]){
                    oldest = old[pictureStat[i]];
                    oldestIdx = i;
                }
            }
        }
        updatePictureStat(student,oldestIdx);
    }
}

void insertPicture(int student){
    int minRec = 0x3f3f3f3f;
    int minCnt = 0;
    for(int i = 1; i <= n; i++) minRec= min(minRec,recommandStat[pictureStat[i]]); //최소추천수 찾기
    for(int i = 1; i <= n; i++) if(minRec == recommandStat[pictureStat[i]]) minCnt++; //최소추천수가 몇개인지 찾기
    deletePicture(minRec,minCnt,student);
}

bool isNewStudent(int student){
    for(int i = 1; i <= n; i++)
        if(pictureStat[i] == student) return false;
    return true;
}

int main(){
    cin >> n;
    cin >> m;
    for(int i = 0; i < m; i++){
        int studentNum;
        cin >> studentNum;
        recommandStat[studentNum]++;
        if(isNewStudent(studentNum)){
            pictureCnt++;
            if(pictureCnt > n) insertPicture(studentNum);
            else pictureStat[pictureCnt] = studentNum;
        }
        updateTime();
    }
    sort(pictureStat+1,pictureStat+1+n);
    for(int i = 1; i <= n; i++) 
        if(pictureStat[i])
            cout << pictureStat[i] << ' ';
}