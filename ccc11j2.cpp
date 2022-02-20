#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, m;
    scanf("%d%d", &h, &m);
    for (int t = 1; t <= m; t++) {
        if ((-6 * t * t * t * t) + (h * t * t * t) + (2 * t * t) + t <= 0) {
            printf("The balloon first touches ground at hour:\n%d", t);
            return 0;
        }
    }
    printf("The balloon does not touch ground in the given time.");
    return 0;
}