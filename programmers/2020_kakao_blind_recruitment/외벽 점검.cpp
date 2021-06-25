#include <bits/stdc++.h>
#define ll long long 
using namespace std;
map <string,int> m;
int distCk[10];
int weakCk[201];

bool isAllCovered(vector<int> &weak){
    for(auto w : weak){
        cout << "COVER : ";
        cout << w << ' ';
        if(!weakCk[w]) return false;
    }
    return true;
}
int solution(int n, vector<int> weak, vector<int> dist) {
    memset(distCk,0,sizeof(distCk));
    memset(weakCk,0,sizeof(weakCk));
    int ans = 0x3f3f3f3f;
    do{

        int wSize = weak.size();
        int dSize = dist.size();
        int cnt = 0;
        memset(distCk,0,sizeof(distCk));
        memset(weakCk,0,sizeof(weakCk));
        for(int i = 0; i < wSize; i++){
            
            
            int gap = weak[(i+1) % wSize] - weak[i];
            if(i == wSize - 1) gap = weak[0] + n - weak[i];
            

            for(int j = 0; j < dSize; j++){
                if(distCk[j]) continue;
                if(gap <= dist[j]){
                   // cout << "GAP : " << weak[i] << ' ' << weak[(i+1)%wSize] << ' ' << gap << '\n';
                    
                    if(i == wSize - 1){
                        for(int k = weak[i]; k <= n; k++) weakCk[k] = 1;
                        for(int k = 0; k <= weak[0]; k++) weakCk[k] = 1;
                    }
                    else{
                        for(int k = weak[i]; k <= weak[i+1]; k++)
                            weakCk[k] = 1;
                    }
                    
                    distCk[j] = 1;
                    cnt++;
                    cout << gap << "군열 : " << weak[i] << "에 " << dist[j] << "사용" << '\n';
                    break;
                }
            }
        }
        cout << "CNT : " << cnt << '\n';
        cout << "WEAK : " ;
        for(int i = 1; i <= 10; i++) cout << weakCk[i] << ' ';
        cout << '\n';
        cout << "DIST : ";
        for(int i = 0; i < dSize; i++) cout << distCk[i] << ' ';
        cout << '\n';
        if(cnt && cnt <= dSize && isAllCovered(weak))
            ans = min(ans,cnt);
        cout << '\n';
        cout << '\n';
    }while(next_permutation(dist.begin(),dist.end()));

    if(ans == 0x3f3f3f3f) return -1;
    return ans;
}