#include <iostream>
#define ll long long
 
int n, m, a, b, c, parent[100001],cnt;
ll weight[100001];
char ch;
 
int find(int x) {
    if (x == parent[x])return x;
    int prev = find(parent[x]);
    weight[x] += weight[parent[x]];
    return parent[x] = prev;
}
 
int main() {
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0)return 0;
        cnt++;
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            weight[i] = 0;
        }
        while (m--) {
            scanf(" %c", &ch);
            if (ch == '!') {
                scanf("%d %d %d", &a, &b, &c);
                int l = find(a);
                int r = find(b);
                if (l != r) {
                    parent[l] = r;
                    weight[l] = weight[b] - weight[a] + c;
                }
            }
            else {
                scanf("%d %d", &a, &b);
                int l = find(a);
                int r = find(b);
                if (l != r) {
                    printf("UNKNOWN\n");
                    continue;
                }
                else printf("%lld\n", weight[a] - weight[b]);
            }
        }
    }
}