#include <iostream>
#include <vector>
using namespace std;
int k;
vector <int> ans;
vector <int> lotto;
void dfs(int idx){
    if(ans.size()==6){
        for(int i = 0; i<6; i++){
            cout << ans[i] << ' ';
        }
        cout <<'\n';
        return;
    }
    for(int i = idx; i<k; i++){
        ans.push_back(lotto[i]);
        dfs(i+1);
        ans.pop_back();
    }
}
int main(){
    while(cin >> k && k!=0){
        lotto = vector<int>(k,0);
        for(int i = 0; i<k; i++) cin >> lotto[i];
        dfs(0);
        cout << '\n';
    }
}