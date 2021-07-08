#include <iostream>
using namespace std;
long GCD(long a, long b) {
	if (b>a) return GCD(b, a);
	if (a%b == 0) return b;
	else  return GCD(b, a%b);
}
int main() {
	long up, down, up1, down1, N, M;
	cin >> up >> down >> up1 >> down1;
	N = down1 * up + up1 * down;
	M = down1 * down;
	
	cout << N/GCD(N,M) << ' ' << M/GCD(N,M);
}