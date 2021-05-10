#include <bits/stdc++.h>
using namespace std;
string board;
string ans;
queue <int> dots;
int piv;
int main(){
    cin >> board;
    for(int i = 0; i < board.size(); i++){
        if(board[i] == '.') dots.push(i);
        if(i == board.size() - 1) dots.push(i + 1);
    }
    while(!dots.empty()){
        int cnt = 0;
        for(int i = piv; i < dots.front(); i++){
            cnt++;
            if(cnt == 4){
                ans += "AAAA";
                cnt = 0;
                piv = i + 1;
            }
           
        }
        
        cnt = 0;
        for(int i = piv; i < dots.front(); i++){
            cnt++;
            if(cnt == 2){
                ans += "BB";
                cnt = 0;
                piv = i + 1;
            }
        }
        if(cnt) { cout << -1; return 0;}
        if(dots.front() < board.size() && board[dots.front()] == '.') ans += '.';
        piv = dots.front() + 1;
        dots.pop();
    }
   
    cout << ans << '\n';
}