#include <bits/stdc++.h>
using namespace std;
string n;
int k, ans;
int d[1000001][11];

int dfs(string num, int count){
    if(count == k) return stoi(num);
    int &ret = d[stoi(num)][count];
    if(ret != -1) return ret;

    for(int i = 0; i < n.size(); i++){
        for(int j = i + 1; j < n.size(); j++){
            swap(num[i],num[j]);
            if(num[0] == '0') {
                swap(num[i],num[j]);
                continue;
            }
            ret = max(ret,dfs(num,count+1));
            swap(num[i],num[j]);
        }
    }
    return ret;
}

int main(){
    cin >> n >> k;
    memset(d,-1,sizeof(d));
    cout << dfs(n,0);
}