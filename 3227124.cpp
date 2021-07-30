#include <bits/stdc++.h>

using namespace std;
int arr[100001] = {0};
int main() {
    int n, m, h;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    while (m--) {
        scanf("%d", &h);
        printf("%ld\n", n - (upper_bound(arr, arr + n, h - 1) - arr + 1) + 1);
    }
    return 0;
}