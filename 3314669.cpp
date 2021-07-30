#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll vil[301][301] = {0};
int main() {
    int n, m, t, s, e, h;
    scanf("%d%d%d", &n, &m, &t);
    while (m--) {
        scanf("%d%d%d", &s, &e, &h);
        vil[s][e] = h;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (vil[i][k] != 0 && i != k) {
                for (int j = 1; j <= n; j++) {
                    if (vil[k][j] != 0 && j != i) {
                        vil[i][j] = (!vil[i][j])? max(vil[i][k], vil[k][j]) : min(vil[i][j], max(vil[i][k], vil[k][j]));
                    }
                }
            }
        }
    }
    while (t--) {
        scanf("%d%d", &s, &e);
        printf("%lld\n", (vil[s][e]) ? vil[s][e] : -1);
    }
    return 0;
}