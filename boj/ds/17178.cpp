#include <bits/stdc++.h>
using namespace std;
int n,i,j, flag;
vector <string> ticketInfo;
vector <string> sequence;
stack <string> s;

bool cmp(string &a, string &b){
    string alpha = a.substr(0,2);
    string alpha2 = b.substr(0,2);
    int num1 = stoi(a.substr(2));
    int num2 = stoi(b.substr(2));
    if(alpha == alpha2) return num1 < num2;
    return a < b;
}

int main(){
    cin >> n;
    for(int i = 0; i < n*5; i++){
        string ticket;
        cin >> ticket;
        ticketInfo.push_back(ticket);
    }
    sequence = ticketInfo;
    sort(sequence.begin(),sequence.end(),cmp);
    
    while(i < 5 * n && j < 5 * n){
        if(ticketInfo[i] == sequence[j]) i++, j++;
        else if(!s.empty() && s.top() == sequence[j]) s.pop(), j++;
        else s.push(ticketInfo[i++]);
    }

    while(!s.empty()){
        if(s.top()!=sequence[j++]){
            flag = 1;
            break;
        }
        s.pop();
    }   

    if(flag) cout << "BAD\n";
    else cout << "GOOD\n";
}