#include <bits/stdc++.h>
using namespace std;
string solution(string &S, int K) {
    string ans = "";
    int size = S.size();
    int ck[100001] = {0};
    int cnt = 0;
    //제일 작은 애를 골라 앞으로
    map <char, vector<int>> m;
    for(int i = 0; i < size; i++) m[S[i]].push_back(i);
    int prev = 0;
    for(auto el : m){
        vector <int> pos = el.second;
        prev = pos[0];
        break;
    }

    for(auto el : m){
        vector <int> pos = el.second;
        for(auto p : pos){
            if(!K) break;
            if(prev > p) {
                if(p > K){
                    swap(S[p-K],S[p]);
                    K = 0;
                    break;
                }
                continue;
            }

            if(p - cnt <= K){
                ck[p] = 1;
                ans += S[p];
                K -= p - cnt;
                cnt++;
                prev = p;
            }
            else{
                swap(S[p-K],S[p]);
                K = 0;
                break;
            }
        }
    }
    for(int i = 0; i < size; i++){
        if(!ck[i]) ans += S[i];
    }
    return ans;
}

// int main(){
//     string S = "decade";
//     cout << solution(S,4);
// }