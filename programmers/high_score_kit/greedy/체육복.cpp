#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector <int> student(n+2,1);
    int answer = 0;
    student[0] = 0;
    student[n+1] = 0;
    for(int i = 0; i < lost.size(); i++) student[lost[i]]--;
    for(int i = 0; i < reserve.size(); i++) student[reserve[i]]++;
    for(int i =1; i<=n; i++){
        if(!student[i]){
            if(student[i-1]==2) student[i-1] = student[i] = 1;
            else if(student[i+1] == 2) student[i+1] = student[i] = 1;
        }
    }
    for(auto s : student){
        if(s) answer++;
    }
    return answer;
}

int main(){
    vector <int> lost = {1,2,3,5};
    vector <int> reserve = {2,4};
    cout << solution(5,lost,reserve);
}

