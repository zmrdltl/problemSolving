#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void aristotle(vector <int> &primeNum,int ck[10001]){
    for(int i = 2; i <= 10000; i++){
        if(!ck[i]) 
            for(int j = i+i; j<10000; j+=i) 
                ck[j] = 1;
    }

    for(int i = 2; i <= 10000; i++)
        if(!ck[i]) primeNum.push_back(i);
}

void backtracking(int pivot,int num, vector<pair<int,int>> &ansCandidates, vector<int> &primeNum){
    if(pivot >= primeNum.size()) return;
    for(int i = 0; i < primeNum.size(); i++){
        if(primeNum[i] + primeNum[pivot] == num){
            ansCandidates.push_back({primeNum[i],primeNum[pivot]});
        }
    }
    backtracking(pivot+1, num, ansCandidates, primeNum);
}

void printSmallest(int n, int ck[10001]){
    pair <int, int> ans(0,0x7f7f7f7f);
    for(int i = 0; i <= n/2; i++){
        if(!ck[i] && !ck[n-i]) {
            if(abs(ans.first-ans.second) > n-i-i){
                ans.first = i;
                ans.second = n-i;
            }
        }
    }
    cout << ans.first << ' ' << ans.second << '\n';
}

int main(){
    fastio;
    int n,t;
    int ck[10001];
    vector <int> primeNum;
    vector <pair <int,int>> ansCandidates;
    aristotle(primeNum,ck);

    cin >> t;
    while(t--){
        ansCandidates.clear();
        cin >> n;
        //backtracking(0,n,ansCandidates,primeNum);
        printSmallest(n, ck);
    }
}