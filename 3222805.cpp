#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d, m = INT_MAX, i;
    scanf("%d%d", &n, &d);
    while (n--) {
        scanf("%d", &i);
        if (!(d % i)) {
            m = min(m, abs(d / i));
        }
    }
    (m == INT_MAX) ? printf("This is not the best time for a trip.") : printf("%d", m);
    return 0;
}