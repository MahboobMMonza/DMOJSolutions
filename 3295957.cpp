#include <bits/stdc++.h>

using namespace std;

int deg[100001] = {0};
int main() {
    int n, a, b, d = 0;
    scanf("%d", &n);
    for (int i = 1; i <n; i++) {
        scanf("%d%d", &a, &b);
        deg[a]++;
        deg[b]++;
    }
    deg[1]++;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) continue;
        d += (int) ceil(log2(deg[i]));
    }
    printf("%d", d + n - 1);
    return 0;
}