#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string words[3], usedAlpha;
int alpha[26], ck[11], flag;
vector <int> digit;

void dfs(int depth){
    if(depth == usedAlpha.size()){
        ll nums[3] = {0};
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < words[i].size(); j++){
                nums[i] *= 10;
                nums[i] += alpha[words[i][j] - 'A'];
            }
        }

        if(nums[0] + nums[1] == nums[2]) flag = 1; 
        return;
    }

    int cur = usedAlpha[depth] - 'A';
    for(int i = 0; i < 10; i++){
        if(ck[i]) continue;
        ck[i] = 1;
        alpha[cur] = i;
        dfs(depth + 1);
        ck[i] = 0;
        alpha[cur]--;
    }
}

int main(){
    cin >> words[0] >> words[1] >> words[2];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < words[i].size(); j++)
            alpha[words[i][j] - 'A'] = 1;

    int cnt = 0;
    for(int i = 0; i < 26; i++)
        if(alpha[i]) usedAlpha += i + 'A',cnt++;

    if(cnt > 10){ cout << "NO"; return 0; } 

    memset(alpha,0,sizeof(alpha));
    dfs(0);        
    if(!flag) cout << "NO\n";
    else cout << "YES\n";
}