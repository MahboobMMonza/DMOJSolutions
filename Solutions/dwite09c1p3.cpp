#include <bits/stdc++.h>

using namespace std;


int main() {
    int m, n, s;
    for (int t = 0; t < 5; t++) {
        scanf("%d", &m);
        s = ((m + 1) * (m + 2)) / 2;
        for (int i = 0; i < m; i++) {
            scanf("%d", &n);
            s -= n;
        }
        printf("%d\n", s);
    }
    return 0;
}