#include <bits/stdc++.h>

using namespace std;

int arr[100000] = {0};
int main() {
    int n, m, x;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    while (m--) {
        scanf("%d", &x);
        printf("%d\n", n - (upper_bound(arr, arr + n, x - 1) - arr));
    }
    return 0;
}