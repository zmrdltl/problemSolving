#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int t;
string keyLog;
list <char> li;
int main(){
    fastio;
    cin >> t;
    while(t--){
        li.clear();
        cin >> keyLog;
        
        auto head = li.begin();

        for(int i = 0; i < keyLog.size(); i++){
            if(keyLog[i] == '>' && head != li.end()) head++;
            else if(keyLog[i] == '<' && head != li.begin()) head--;
            else if(keyLog[i] == '-' && head != li.begin()) head = li.erase(--head);
            else if(keyLog[i] != '>' && keyLog[i] != '<' && keyLog[i] != '-') li.insert(head,keyLog[i]);
        }

        for(auto l : li) cout << l;
        cout << '\n';
    }
}