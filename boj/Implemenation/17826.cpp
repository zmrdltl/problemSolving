#include <bits/stdc++.h>
using namespace std;
int score[50];
int hongik;

string getDegree(int rank){
    if(rank <= 5) return "A+";
    if(rank <= 15) return "A0";
    if(rank <= 30) return "B+";
    if(rank <= 35) return "B0";
    if(rank <= 45) return "C+";
    if(rank <= 48) return "C0";
    return "F";
}

int main(){
    for(int i = 0; i < 50; i++) cin >> score[i];
    cin >> hongik;
    int cnt = 1;
    for(int i = 0; i < 50; i++){
        if(hongik == score[i]) break;
        cnt++;
    }
    cout << getDegree(cnt);
}