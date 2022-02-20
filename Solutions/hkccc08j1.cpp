#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, w, c = 0, n = 0, t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &w, &l);
        c = max(c, l * w);
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &w, &l);
        n = max(n, l * w);
    }
    (c == n) ? printf("Tie") : (c > n) ? printf("Casper") : printf("Natalie");
    return 0;
}