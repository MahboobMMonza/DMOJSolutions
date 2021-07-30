#include <bits/stdc++.h>

using namespace std;

int t[1000001] = {0};
int main() {
    int m = 2;
    scanf("%d%d", &t[0], &t[1]);
    t[2] = t[0] - t[1];
    while (t[m] >= 0 && t[m] <= t[m - 1]) {
        t[m + 1] = t[m - 1] - t[m];
        m++;
    }
    printf("%d", m + 1);
    return 0;
}