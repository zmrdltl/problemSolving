#include <iostream>
#include <string>
#include <stack>
using namespace std;
int recursion(string s,int ans, int pivot,char prev){
    if(pivot==s.size()) return ans;
    if(s[pivot]=='(')ans += recursion(s,ans,pivot+1);

}
int main(){
    string s;
    int ans = 0;
    cin >> s;
    cout << recursion(s,ans,0);
}