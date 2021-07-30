#include <bits/stdc++.h>

using namespace std;

int d[100002] = {0}, arr[100001] = {0};
int main() {
    int n, m, t, x, c;
    scanf("%d%d%d", &n, &t, &m);
    while (m--) {
        scanf("%d", &x);
        if (x == 1) {
            d[2]--;
            d[n + 1]++;
        } else {
            d[1]--;
            d[x]++;
            d[x+1]--;
            d[n+1]++;
        }
    }
    arr[0] = t;
    c = n;
    for (int i = 1; i <= n; i++) {
        arr[i] = arr[i - 1] + d[i];
        c -= (arr[i] <= 0);
    }
    printf("%d", c);
    return 0;
}