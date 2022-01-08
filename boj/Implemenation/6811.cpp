#include <bits/stdc++.h>
using namespace std;

int troutPoints, pikePoints, pickerelPoints, totalPoints, cnt;

int main(){
    cin >> troutPoints >> pikePoints >> pickerelPoints >> totalPoints;
    for(int i = 0; i <= 100; i++) 
        for(int j = 0; j <= 100; j++)
            for(int k = 0; k <= 100; k++)
                if(i || j || k){
                    if(i * troutPoints + j * pikePoints + k * pickerelPoints <= totalPoints) {
                        printf("%d Brown Trout, %d Northern Pike, %d Yellow Pickerel\n", i, j, k);
                        cnt++;
                    }
                }
    printf("Number of ways to catch fish: %d", cnt); 
}