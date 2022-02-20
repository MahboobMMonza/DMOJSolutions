#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll a[2005] = {0};
    int t, c, r, n, l, m;
    bool f;
    ll d, h;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 2002; i++) {
            a[i] = 0;
        }
        scanf("%d%d", &l, &n);
        while (n--) {
            scanf("%d%d%lld", &c, &r, &d);
            a[max(c - r, 1)] += d;
            a[c + r + 1] -= d;
        }
        scanf("%d", &m);
        while (m--) {
            d = 0;
            f = 1;
            scanf("%lld", &h);
            for (int i = 1; i <= l; i++) {
                d += a[i];
                h -= d;
                if (h <= 0) {
                    printf("%d\n", i);
                    f = 0;
                    break;
                }
            }
            if (f) printf("Bloon leakage\n");
        }
    }
}