#include <bits/stdc++.h>
using namespace std;

vector <int> solution(vector<string> operations){
    deque <int> dq;
    vector <int> answer;
    for(int i = 0; i < operations.size(); i++){
        int num = stoi(operations[i].substr(2));
        
        if(operations[i][0]=='I'){
            dq.push_back(num);
            sort(dq.begin(),dq.end());
        }else{
            if(!dq.size())continue;
            if(num == 1) dq.pop_back();
            else if(num == -1) dq.pop_front();
        }
    }
    if(!dq.size()){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        answer.push_back(max(dq[0], dq[dq.size()-1]));
        answer.push_back(min(dq[0], dq[dq.size()-1]));
    }
    return answer;
}