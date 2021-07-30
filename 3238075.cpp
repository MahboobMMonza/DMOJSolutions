#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll arr[1000002] = {0}, ps[1000001] = {0};
int main() {
    ll n, t, a, b, d, m = 0, l = 0, r = 1, s = 0;
    scanf("%lld%lld", &n, &t);
    while (t--) {
        scanf("%lld%lld%lld", &a, &b, &d);
        arr[a] += d;
        arr[b + 1] -= d;
    }
    scanf("%lld", &d);
    for (int i = 1; i <= n; i++) {
        ps[i] = (s += arr[i]) + ps[i - 1];
    }
    while (r <= n) {
        if (ps[r] - ps[l] <= d) {
            m = max(m, r - l);
            r++;
        } else l++;
    }
    printf("%lld", m);
    return 0;
}