#include <bits/stdc++.h>

using namespace std;

int main() {
    int g, n, mi, ma, a;
    scanf("%d", &g);
    while (g--) {
        scanf("%d", &n);
        mi = 101, ma = 0;
        while (n--) {
            scanf("%d", &a);
            mi = min(a, mi);
            ma = max(a, ma);
        }
        printf("%d %d\n", mi, ma);
    }
    return 0;
}