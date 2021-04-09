#include <bits/stdc++.h>
using namespace std;
int n;
string word[101];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> word[i];
    }
    for(int i = 0; i < n - 1; i++){
        if(word[i][word[i].size()-1] != word[i + 1][0]){
            cout << 0;
            return 0;
        }

    }
    cout << 1;
}