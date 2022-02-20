#include <bits/stdc++.h>

using namespace std;

int main() {
    int m[3] = {0};
    double a, b;
    for (int i = 0; i < 3; i++) {
        scanf("%d", &m[i]);
    }
    a = ((m[0] > 100) * 0.25 * (m[0] - 100)) + (0.15 * m[1]) + (0.20 * m[2]);
    b = ((m[0] > 250) * 0.45 * (m[0] - 250)) + (0.35 * m[1]) + (0.25 * m[2]);
    printf("Plan A costs %.2lf\n", a);
    printf("Plan B costs %.2lf\n", b);
    (a < b) ? printf("Plan A is cheapest.") : (b < a) ? printf("Plan B is cheapest.") : printf("Plan A and B are the same price.");
    return 0;
}