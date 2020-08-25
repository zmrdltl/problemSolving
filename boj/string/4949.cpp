#include <iostream>
#include <string>
#include <stack>
using namespace std;

string getBracketStr(string sentance){
    string tmp="";
    for(int i = 0; i<sentance.size(); i++){
        if(sentance[i]=='[' || sentance[i]==']' ||
        sentance[i]=='(' || sentance[i]==')')
        tmp+=sentance[i];
    }
    return tmp;
}

string isBalanced(string bracketStr){
    stack <char> s;
    for(int i = 0; i<bracketStr.size(); i++){
        if(bracketStr[i]=='(' || bracketStr[i]=='[') s.push(bracketStr[i]);
        else{
            if(!s.size()) return "no\n";
            if(s.top()=='(' && bracketStr[i]==')' ||
               s.top()=='[' && bracketStr[i]==']'
            ) s.pop(); 
            else return "no\n";
        }
    }
    if(!s.size()) return "yes\n";
    return "no\n";
}

int main(){
    while(1){
        string sentance;
        string bracketStr;
        getline(cin,sentance);
        if(sentance==".") break;
        bracketStr = getBracketStr(sentance);
        cout << isBalanced(bracketStr);
    }
}