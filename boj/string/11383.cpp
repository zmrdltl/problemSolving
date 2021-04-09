#include <bits/stdc++.h>
using namespace std;
int n,m;
string word[10], word1[10];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> word[i];
    for(int i = 0; i < n; i++) cin >> word1[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < word[i].size(); j++){
            for(int k = j*2; k < j*2 + 2; k++){
                if(word[i][j] != word1[i][k]){
                    cout << "Not Eyfa\n";
                    return 0;
                }
            }
        }
    }
    cout << "Eyfa";
}