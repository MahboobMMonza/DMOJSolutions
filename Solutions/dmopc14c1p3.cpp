#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i, x;
    double s = 0, p = 0;
    scanf("%d", &n);
    p = n;
    while (n--) {
        scanf("%d", &x);
        s += x;
    }
    scanf("%d", &i);
    while (i--) {
        p++;
        scanf("%d", &x);
        s += x;
        printf("%lf\n", s / p);
    }
    return 0;
}