#include <bits/stdc++.h>
using namespace std;
#define MAX 128
char s[MAX];
int main() {
    int i,j,k,cases;
    fgets(s,MAX,stdin);
    sscanf(s,"%d",&cases);
    while(cases--) {
        fgets(s,MAX,stdin);
        i=0;
        j=strlen(s);
        while(i<j && isspace(s[i])) i++;
        while(j>i && isspace(s[j-1])) s[--j]=0;
        if(i==j) goto fail;
        for(k=i;k<j;k++) if(!isdigit(s[k])) goto fail;
        while(i<j-1 && s[i]=='0') i++;
        puts(s+i);
        continue;
        fail:
        puts("invalid input");
    }
}