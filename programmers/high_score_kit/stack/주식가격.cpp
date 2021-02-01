#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    int pSize = prices.size();
    vector <int> answer(pSize);
    stack <int> s;
    for(int i = 0; i < pSize; i++){
        while(!s.empty() && prices[s.top()] > prices[i]){
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        answer[s.top()] = pSize - s.top() - 1;
        s.pop();
    }
    return answer;
}