#include <bits/stdc++.h>

using namespace std;

int s[500001];
int main() {
    int n, q, a, b;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }
    while (q--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", s[n] - s[b] + s[a - 1]);
    }
    return 0;
}