
#include <cstdio>
using namespace std;
const int MOD = 1e9 + 7;
int f[1000001];
int g[1000001];

int main() {
    int n;
    scanf("%d", &n);

    // f(n) = f(n-2)+2*g(n)
    // g(n) = f(n-1)+f(n-2)+g(n-2)
    f[0] = 1; f[1] = 2;
    g[0] = 0; g[1] = 1;
    for (int i = 2; i <= n; ++i) {
        g[i] = ((f[i - 1] + f[i - 2]) % MOD + g[i - 2]) % MOD;
        f[i] = (f[i - 2] + (2 * g[i]) % MOD) % MOD;
    }

    printf("%d\n", f[n]);

}