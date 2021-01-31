#include <bits/stdc++.h>
using namespace std;
int n;
int team[20][20];
int check[20];
int ans = 0x7f7f7f7f;

int getSynergy(vector <int> &oneTeam){
    int synergy = 0;
    int size = oneTeam.size();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(i!=j){
                synergy += team[oneTeam[i]][oneTeam[j]];
            }
        }
    }
    return synergy;
}   

void backTracking(int depth,int idx){
    if(depth==n/2) {
        vector <int> aTeam;
        vector <int> bTeam;
        for(int i = 0; i < n; i++) {
            if(check[i]) aTeam.push_back(i);
            else bTeam.push_back(i);
        }
        
        int aSynergy = getSynergy(aTeam);
        int bSynergy = getSynergy(bTeam);
        ans = min(ans,abs(aSynergy - bSynergy));
        return;
    }

    for(int i = idx; i < n; i++){
        if(check[i]) continue;
        check[i] = 1;
        backTracking(depth+1,i+1);
        check[i] = 0;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) 
            cin >> team[i][j];
    
    backTracking(0,0);
    cout << ans <<'\n';
}