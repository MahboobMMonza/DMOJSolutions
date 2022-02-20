#include <bits/stdc++.h>

using namespace std;

int arr[1000001] = {0};
int main() {
    int n, q, a, b;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        arr[i] += arr[i - 1];
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", arr[b + 1] - arr[a]);
    }
    return 0;
}