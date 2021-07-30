#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll ro[200002] = {0}, t[200002] = {0};
int main() {
    ll k;
    int n, m, a, b, l = 0, r = 1, w = 0;
    scanf("%d%d%lld", &n, &m, &k);
    if (k == 0) {
        printf("0");
        return 0;
    }
    ro[0] = m;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        ro[a]--;
        ro[b + 1]++;
    }
    for (int i = 1; i <= n; i++) {
        ro[i] += ro[i - 1];
    }
    t[1] = ro[1];
    for (int i = 2; i <= n; i++) {
        t[i] = ro[i] + t[i - 1];
    }
    while (r <= n) {
        if (t[r] - t[l] >= k) {
            w = (w == 0) ? r - l : min(w, r - l);
            l++;
        } else r++;
    }
    (w == 0) ? printf("-1") : printf("%d", w);
    return 0;
}