#include <bits/stdc++.h>
using namespace std;
int n, ans = 0x3f3f3f3f, people[21], ck[21], ability[21][21];
vector <int> teamA, teamB;

void pickTeam(int depth, int idx,int pickNum){
    if(depth == pickNum){
        teamA.clear();
        teamB.clear();

        for(int i = 0; i < n; i++){
            if(people[i]) teamA.push_back(i);
            else teamB.push_back(i);
        }

        int a = 0, b = 0;

        for(int i = 0; i < teamA.size(); i++){
            for(int j = 0; j < teamA.size(); j++){
                a += ability[teamA[i]][teamA[j]];
            }
        }

        for(int i = 0; i < teamB.size(); i++){
            for(int j = 0; j < teamB.size(); j++){
                b += ability[teamB[i]][teamB[j]];
            }
        }
        
        ans = min(ans,abs(a-b));
        return;
    }
    
    for(int i = idx; i < n; i++){
        if(ck[i]) continue;
        ck[i] = 1;
        people[i] = 1;
        pickTeam(depth + 1, i + 1, pickNum);
        people[i] = 0;
        ck[i] = 0;
    }
}


int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> ability[i][j];
        }
    }

    //i¸í »Ì´Â´Ù. 1ÆÀ : i, 2ÆÀ : n-i¸í
    for(int i = 1; i <= n/2; i++){
        memset(ck,0,sizeof(ck));
        pickTeam(0,0,i);
    }
    cout << ans;
}