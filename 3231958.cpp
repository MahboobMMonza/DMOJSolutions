#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll t[100002] = {0};
int main() {
    int s, n, j, a, b, k, c = 0, ct = 0;
    scanf("%d%d%d", &s, &n, &j);
    while (j--) {
        scanf("%d%d%d", &a, &b, &k);
        t[a] += k;
        t[b + 1] -= k;
    }
    for (int i = 1; i <= s; i++) {
        ct += t[i];
        c += (ct < n);
    }
    printf("%d", c);
    return 0;
}