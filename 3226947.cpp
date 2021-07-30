#include <bits/stdc++.h>

using namespace std;

int d[100002], s[100001];

int main() {
    int n, t, m, c = 0;
    scanf("%d%d%d", &n, &s[0], &m);
    while (m--) {
        scanf("%d", &t);
        if (t == 1) {
            d[2]--;
            d[n + 1]++;
        }
        else {
            d[1]--;
            d[t]++;
            d[t + 1]--;
            d[n + 1]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + d[i];
        c += (s[i] > 0);
    }
    printf("%d", c);
    return 0;
}