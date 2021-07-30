#include <bits/stdc++.h>

using namespace std;

int v[101] = {0}, b[100];
int main() {
    int m, n;
    while (true) {
        scanf("%d%d", &m, &n);
        if (m == 0) {
            break;
        }
        for (int i = 1; i < 101; i++) {
            v[i] = b[i - 1] = 0;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            v[b[i]] = 1;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i] && i + b[j] <= m) {
                    v[i + b[j]] =(v[i + b[j]]) ? min(v[i + b[j]], v[i] + 1) : v[i] + 1;
                }
            }
        }
        printf("%d\n", (v[m]) ? v[m] : -1);
    }
    return 0;
}