#include <bits/stdc++.h>
using namespace std;
vector <long long> nums;
vector <char> ops, pri = {'+', '-', '*'};

long long getRes(long long a, char o, long long b){
    if(o == '+') return a + b;
    if(o == '-') return a - b;
    return a * b;
}

long long solution(string expression) {
    nums.clear();
    ops.clear();
    
    sort(pri.begin(), pri.end());
    
    long long answer = 0;
    string tmp;
    for(auto e : expression){
        if(e == '+' || e == '-' || e == '*') {
            ops.push_back(e);
            nums.push_back(stoll(tmp));
            tmp = "";
        }
        else tmp += e;   
    }
    nums.push_back(stoll(tmp));
    
    vector <char> op;
    vector <long long> num;
    
    do{
        num = nums;
        op = ops;
        for(int i = 0; i < pri.size(); i++){
            int sz = op.size();
            for(int j = 0; j < op.size(); j++){
                if(pri[i] == op[j]){
                    long long res = getRes(num[j],op[j],num[j+1]);
                    num.erase(num.begin() + j);
                    op.erase(op.begin() + j);
                    num[j] = res;
                    j--;
                }
            }
        }
        answer = max(answer, abs(num[0]));
    }while(next_permutation(pri.begin(), pri.end()));
    
    return answer;
}