#include <bits/stdc++.h>
using namespace std;
int t, highestPoly;
string str;

vector <string> split(string input, char delimiter){
    vector <string> result;
    stringstream ss(input);
    string tmp;
    while(getline(ss,tmp,delimiter)) result.push_back(tmp);
    return result;
}

int main(){
    cin >> t;
    cin.ignore();
    for(int i = 1; i <= t; i++){
        getline(cin, str);
        vector <string> v = split(str, ' ');
        vector <int> ans;
        highestPoly = stoi(v[0]);
        for(int i = 1; i <= highestPoly; i++){
            int num = stoi(v[i]) * (highestPoly - i + 1);
            ans.push_back(num);
        }
        cout << "Case " << i << ": " << highestPoly - 1 << ' ';
        for(auto e : ans) cout << e << ' ';
        cout << '\n';
    }
}