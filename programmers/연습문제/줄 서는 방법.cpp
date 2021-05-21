#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll fact(int num){
    ll sum = 1;
    for(int i = 2; i <= num; i++) sum *= i;
    return sum;
}

vector<int> solution(int n, ll k) {
    vector<int> answer;
    vector <int> ck(n + 1);
    
    for(int i = 1; i <= n; i++){
        ll cnt = 0;
        for(int j = 1; j <= n; j++){
            if(!ck[j] && cnt + fact(n - i) < k) cnt += fact(n - i);
            else{
                if(!ck[j]){ 
                    k -= cnt; 
                    ck[j] = 1;
                    answer.push_back(j); 
                    break;
                }
            }
        }
    }
    return answer;
}