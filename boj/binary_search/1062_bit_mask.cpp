#include <bits/stdc++.h>
using namespace std;
int n, k, teached;
int words[51];

int backtracking(int depth, int idx){
    int ret = 0;
    if(depth == k - 5){
        for(int i = 0; i < n; i++){
            if((words[i] & teached) == words[i]) ret++;
        }
        return ret;
    }

    for(int i = idx; i < 26; i++){
        if(teached & (1<<i)) continue;
        teached |= (1 << i);
        ret = max(ret,backtracking(depth + 1, i + 1));
        teached &= ~(1 << i);
    }
    return ret;
}

int main(){
    cin >> n >> k;
    string w;
    for(int i = 0; i < n; i++) {
        cin >> w;
        for(int j = 0; j < w.size(); j++) words[i] |= 1 << (w[j] - 'a');
    }
    if(k < 5) {cout << 0; return 0;}
    teached |= 1 << ('a' - 'a');
    teached |= 1 << ('c' - 'a');
    teached |= 1 << ('i' - 'a');
    teached |= 1 << ('t' - 'a');
    teached |= 1 << ('n' - 'a');

    cout << backtracking(0,0);

}