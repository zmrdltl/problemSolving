#include <bits/stdc++.h>
using namespace std;
string minWord;
int n, length, sum;
vector <string> DNA;
int main(){
    cin >> n >> length;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        DNA.push_back(s);
    }
    for(int i = 0; i < length; i++){
        int alphaCnt[26] = {0};
        int big = 0;
        char maxAlpha;
        for(int j = 0; j < n; j++){
            alphaCnt[DNA[j][i] - 'A']++;
            big = max(big,alphaCnt[DNA[j][i] - 'A']);
        }
        for(int k = 0; k < 26; k++){
            if(alphaCnt[k] == big){
                minWord += k + 'A';
                maxAlpha = k + 'A';
                break;
            }
        }
        for(int k = 0; k < 26; k++){
            if(k + 'A' != maxAlpha) sum += alphaCnt[k];
        }
    }
    cout << minWord << '\n' << sum << '\n';
}