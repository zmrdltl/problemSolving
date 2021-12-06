#include <bits/stdc++.h>
using namespace std;
map <int,int> m;
int main(){
    for(int i = 2; i <= 100; i++) m[pow(i,3)] = i;
    for(int a = 2; a <= 100; a++){
        for(int b = 2; b <= 100; b++){
            for(int c = 2; c <= 100; c++){
                int d3 = pow(a,3) - (pow(b,3) + pow(c,3));
                if(!m[d3]) continue;
                if(b < c && c < m[d3])
                    printf("Cube = %d, Triple = (%d,%d,%d)\n", a,b,c,m[d3]);
            }
        }
    }
}