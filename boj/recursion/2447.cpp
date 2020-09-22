#include <bits/stdc++.h>
using namespace std;
int n;
char space[2200][2200];
void star(int x, int y, int num){
    if(num==1) {space[x][y] = '*'; return;}
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i!=1 || j!=1){
                star(x + i*(num/3), y + j*(num/3), num/3);
            }
        }
    }
}
int main(){
    cin >> n;
    memset(space,' ',sizeof(space));
    star(0,0,n);
    for(int i = 0; i <n; i++){
        for(int j = 0 ; j < n; j++)
            cout << space[i][j];
        cout << '\n';
    }
}