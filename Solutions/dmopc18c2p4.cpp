#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll s[500001] = {0};
int main() {
    ll m;
    int n, l = 0, r = 1, k = 0;
    scanf ("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &s[i]);
        s[i] += s[i - 1];
    }
    while (r <= n) {
        if (s[r] - s[l] >= m) {
            (k == 0) ? k = r - l : k = min(k, r - l);
            if (k == 1) break;
            l++;
        } else r++;
    }
    (k > 0) ? printf("%d", k) : printf("-1");
    return 0;
}