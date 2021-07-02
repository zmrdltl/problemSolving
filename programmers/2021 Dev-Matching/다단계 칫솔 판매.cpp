#include <bits/stdc++.h>
using namespace std;
unordered_map <string,string> parent;
unordered_map <string,int> profits;

void updateProfit(string name, int money){
    if(name == "-" || !money) return;
    int charge = money * 0.1;
    profits[name] += money - charge;
    updateProfit(parent[name], charge);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    for(int i = 0; i < referral.size(); i++) parent[enroll[i]] = referral[i];
    for(int i = 0; i < seller.size(); i++) updateProfit(seller[i],amount[i] * 100);
    for(int i = 0; i < enroll.size(); i++) answer.push_back(profits[enroll[i]]);
    return answer;
}