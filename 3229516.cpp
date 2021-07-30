#include <bits/stdc++.h>

using namespace std;

int l[1001], c[1000];
int main() {
    int n, a, t;
    for (int x = 0; x < 10; x++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &c[i]);
            l[c[i]] = i;
        }
        a = 0;
        for (int i = n - 1; i > 0; i--) {
            if (l[i] > l[i + 1]) {
                t = c[l[i]];
                a += l[i];
                for (int j = l[i]; j > 0; j--) {
                    c[j] = c[j - 1];
                    l[c[j]]++;
                    c[j - 1] = t;
                }
                l[i] = 0;
            }
        }
        printf("%d\n", a);
    }
    return 0;
}