#include <bits/stdc++.h>
using namespace std;

string andOp(string a,string b){
    string tmp = "";
    for(int i = 0; i < a.size(); i++){
        if(a[i] == b[i] && a[i] == '1') tmp+="1";
        else tmp += "0";
    }
    return tmp;
}

string orOp(string a,string b){
    string tmp = "";
    for(int i = 0; i < a.size(); i++){
        if(a[i] == b[i] && a[i] == '0') tmp+="0";
        else tmp += "1";
    }
    return tmp;
}

string xorOp(string a,string b){
    string tmp = "";
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]) tmp+="1";
        else tmp += "0";
    }
    return tmp;
}

string notOp(string a){
    string tmp = "";
    for(int i = 0; i < a.size(); i++){
        if(a[i]=='0') tmp+="1";
        else tmp+="0";
    }
    return tmp;
}

int main(){
    string a,b;
    cin >> a >> b;
    cout << andOp(a,b) <<'\n';
    cout << orOp(a,b) <<'\n';
    cout << xorOp(a,b) <<'\n';
    cout << notOp(a) <<'\n';
    cout << notOp(b) <<'\n';
}