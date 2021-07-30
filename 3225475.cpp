#include <bits/stdc++.h>

using namespace std;

int f[10000001] = {0};
int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i < 10000001; i++) {
        f[i] = i;
    }
    for (int i = 2; i * i < 10000001; i++) {
        if (f[i] == i) {
            for (int j = i * i; j < 10000001; j += i) {
                if (f[j] == j) {
                    f[j] = i;
                }
            }
        }
    }
    while (n--) {
        scanf("%d", &m);
        while (m > 1) {
            printf("%d ", f[m]);
            m /= f[m];
        }
        printf("\n");
    }
    return 0;
}