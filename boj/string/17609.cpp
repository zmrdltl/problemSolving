#include <bits/stdc++.h>
using namespace std;
int t;
string s;

int isPalin(string s){
    for(int i = 0; i < s.size()/2; i++)
        if(s[i] != s[s.size() - 1 - i]) 
            return 0;
    return 1;
}

int nearPalin(int left,int right,bool skip){
    if(left > right) return 1;
    if(s[left] == s[right]) return nearPalin(left+1,right-1,skip);
    if(!skip) return max(nearPalin(left+1,right,1),nearPalin(left,right-1,1));
    else return 0;
}

int classifier(string s){
    if(isPalin(s)) return 0;
    if(nearPalin(0,s.size()-1,0)) return 1;
    return 2;
}

int main(){
    cin >> t;
    while(t--){
        cin >> s;
        cout << classifier(s)<< '\n';
    }

}