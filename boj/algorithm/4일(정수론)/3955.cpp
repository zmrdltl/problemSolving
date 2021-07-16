#include <cstdio>
#define ll long long
using namespace std;
ll gcd(ll A, ll B){
    if (B == 0) return A;
    return gcd(B, A%B);
}

ll extended_gcd(ll A, ll B){
    ll r, q, tmpA = A, t, t1 = 0, t2 = 1;
    while (B != 0){
        q = A / B;
        r = A%B;
        t = t1 - q*t2;
        A = B;
        B = r;
        t1 = t2;
        t2 = t;
    }

    while (t1<0) t1 += tmpA;
    return t1;
}

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        ll K, C;
        scanf("%lld%lld", &K, &C);

        if (C == 1){        // 0 이될 수 밖에 없음
            if (K + 1 > 1e9)
                printf("IMPOSSIBLE\n");
            else
                printf("%lld\n", K + 1);
            continue;
        }

        else if (K == 1){
            printf("1\n");
            continue;
        }

        else if (gcd(K, C) != 1){
            printf("IMPOSSIBLE\n");
            continue;
        }
        //   y:우리가 구하고자하는 답, x: K*x개를 사야함
        //     C*y = K*x + 1
        //   C*y - K*x = 1 or C*y % K = 1 (단 C,K는 서로소)
        ll ans = extended_gcd(K, C);
        if (ans > 1e9)
            printf("IMPOSSIBLE\n");
        else
            printf("%lld\n", ans);
    }

}
