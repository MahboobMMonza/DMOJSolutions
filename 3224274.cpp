#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t, c, v, h = 0;
    scanf("%d%d", &n, &t);
    while (n--) {
        scanf("%d%d", &c, &v);
        if (c <= t) {
            h = max(h, v);
        }
    }
    printf("%d", h);
    return 0;
}