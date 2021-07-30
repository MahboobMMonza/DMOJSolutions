#include <bits/stdc++.h>

using namespace std;

int t[20], d[20];
int main() {
    int n, a, p;
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &t[i]);
        }
        if (n == 1) {
            printf("0\n");
            continue;
        }
        for (int i = 0; i < n - 1; i++) {
            d[i] = t[i + 1] - t[i];
        }
        p = 1;
        while (true) {
            a = 0;
            while (a + p < n - 1) {
                if (d[a] != d[a + p]) break;
                else a++;
            }
            if (a + p == n - 1) {
                break;
            } else p++;
        }
        printf("%d\n", p);
    }
    return 0;
}