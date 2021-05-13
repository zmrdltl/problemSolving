#include <bits/stdc++.h>
using namespace std;
int n, k, ans, ck[26];
vector <string> words;
string comb,alphas = "bdefghjklmopqrsuvwxyz";
void dfs(int depth, int idx){
    if(depth == k - 5){
        int cnt = 0;
        map <char,int> m;
        for(auto &a : comb) m[a] = 1;
        for(int i = 0; i < words.size(); i++){
            int flag = 0;
            for(auto &cur : words[i]){
                if(cur == 'a' || cur == 'n' || cur == 'c' || cur == 'i' || cur == 't') continue;
                if(!m[cur]) {flag = 1; break;}
            }
            if(!flag) cnt++;
        }
        ans = max(ans,cnt);
        return;
    }

    for(int i = idx; i < alphas.size(); i++){
        if(ck[i]) continue;
        ck[i] = 1;
        comb.push_back(alphas[i]);
        dfs(depth + 1, i + 1);
        comb.pop_back();
        ck[i] = 0;
    }   
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        map<char,int> tmp;
        string s, t;
        cin >> s;
        string part = s.substr(4, s.size() - 8);
        for(int i = 0; i < part.size(); i++) tmp[part[i]] = 1;
        for(auto el : tmp) t += el.first;
        words.push_back(t); 
    }

    if(k < 5) { //'a', 'n', 't', 'i', 'c'도 못가르친다면 단어를 읽을 수 없다.
        cout << 0; return 0;
    }
    
    dfs(0,0);

    cout << ans << '\n';
}