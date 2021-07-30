#include <bits/stdc++.h>

using namespace std;

int arr[1000001] = {0};
int main() {
    int n, f, s, d, m, l = 0, r;
    scanf("%d%d", &n, &d);
    r = n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        arr[i] += arr[i - 1];
    }
    while (d--) {
        scanf("%d", &m);
        s = arr[r] - arr[m + l];
        f = arr[m + l] - arr[l];
        (f > s) ? printf("%d\n", f) : printf("%d\n", s);
        (f > s) ? l += m : r = l + m;
    }
    return 0;
}