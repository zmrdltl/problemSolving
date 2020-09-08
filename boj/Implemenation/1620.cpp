#include <iostream>
#include <string>
#include <vector>
#include <map>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    fastio;
    int n,m;
    map <string,int> encyclopedia;
    vector <string> vec_encyclopedia(100001);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string pokemonName;
        cin >> pokemonName;
        encyclopedia[pokemonName]=i;
        vec_encyclopedia[i] = pokemonName;
    }
    while(m--){
        string x;
        cin >> x;
        if('1'<=x[0] && x[0] <= '9') //숫자일 경우
            cout << vec_encyclopedia[stoi(x)]<<'\n';
        else // 포켓몬 이름일 경우
            cout << encyclopedia[x]<<'\n';
    }
}