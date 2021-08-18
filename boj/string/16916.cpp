#include <bits/stdc++.h>
using namespace std;
char s[1000001],p[1000001];
int main(){
    scanf("%s%s",s,p);
    printf("%d",strstr(s,p)!=0);
}