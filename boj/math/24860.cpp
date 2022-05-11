#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll vk, jk, va, ja, vh, dh, jh, lightChainK, lightChainA, heavyChain;
int main(){
  cin >> vk >> jk >> va >> ja >> vh >> dh >> jh;
  lightChainK = vk * jk;
  lightChainA = va * ja;
  heavyChain = vh * dh * jh;
  cout << heavyChain*(lightChainA + lightChainK);
}