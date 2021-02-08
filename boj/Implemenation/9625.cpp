#include <bits/stdc++.h>

using namespace std;
int a[45];
int b[45];
int pushed;
int main(void){
	cin >> pushed;
	a[0]=1;
	b[1]=1;
	for (int i = 2; i < pushed + 1; i++){
		a[i] = b[i - 1];
		b[i] = a[i - 1] + b[i - 1];
	}
	cout << a[pushed] << " " << b[pushed];
}