#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int arr[200001];
int main() {
    int m, n, k;
    ll ans = 0;
    scanf("%d%d%d", &m, &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + k);
    for (int h = k - 1, l = 0; l <= h;) {
        int f = arr[h]; h--;
        for (int r = 1; r < m && l <= h; r++, l++) {
            ans += f - arr[l] + r;
        }
    }
    printf("%lld", ans);
    return 0;
}