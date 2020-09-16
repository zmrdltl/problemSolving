#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
using namespace std;
int n,m,ans=0;
string word;
//IOI 1
//IOIOI 2
//I한번나오면 n개수만큼 OI가 나올 때마다 답  1증가
int main(){
    fastio;
    cin >> n >> m >> word;

    for(int i = 1; i < word.size(); i++){
        int count = 0;
        if(word[i-1]=='I'){
            //int j = i;
            while(word[i]=='O' && word[i+1]=='I'){
                i+=2;
                count++;
                if(count == n ){ count--; ans++;}
            }
        }
    }

    cout << ans <<'\n';
}
