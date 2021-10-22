#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solution(int price, int money, int count){
    ll m = money;
    for(int i = 1; i <= count; i++) m -= price * i;
    if(m >= 0) return 0;
    return llabs(m);
}