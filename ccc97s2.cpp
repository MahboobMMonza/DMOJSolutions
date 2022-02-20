#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        bool f = 0;
        for (int i = 1; i * i <= n; i++) {
            if (!(n % i)) {
                for (int j = 1; j * j <= n; j++) {
                    if (!(n % j) && (n / i) - i == (n / j) + j) {
                        f = 1;
                    }
                    if (f) break;
                }
            }
            if (f) break;
        }
        f ? printf("%d is nasty\n") : printf("%d is not nasty\n");
    }
    return 0;
}