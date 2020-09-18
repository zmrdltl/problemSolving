#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int testCase, a, b;
string answer;
int ansSize = 0x7f7f7f7f;
int ck[10001];
int D(int num){
    num *= 2;
    if(num > 9999) return num % 10000;
    return num;
}
int S(int num){
    if(num - 1 <= 0) return 9999;
    return num - 1;
}

int L(int num){
    string numString = to_string(num);
    string tmp = "";
    for(int i = 1; i<numString.size(); i++){
        tmp += numString[i];
    }
    tmp+=numString[0];
    return stoi(tmp);
}

int R(int num){
    string numString = to_string(num);
    string tmp = "";
    tmp+=numString[numString.size()-1];
    for(int i = 0; i<numString.size()-1; i++){
        tmp += numString[i];
    }
    return stoi(tmp);
}

string dfs(string ans, int num){
    int ret = num;
    if(ck[ret]) return ans;

    if(num == b){
        cout << "i did it" <<'\n';
        if(ansSize > ans.size()){
            ansSize = ans.size();

        }
        return ans;

    }
    int tmp = num;
    if(ck[tmp]==0){
        ck[tmp] = 1;
        dfs(ans+"D",D(tmp));
        dfs(ans+"S",S(tmp));
        dfs(ans+"L",L(tmp));
        dfs(ans+"R",R(tmp));
        ck[tmp] = 0;
    }
   
}

int main(){
    cin >> testCase;
    while(testCase--){
        memset(ck,0,sizeof(ck));
        ansSize = 0x7f7f7f7f;
        cin >> a >> b;
        cout << dfs("",a);
    }
}