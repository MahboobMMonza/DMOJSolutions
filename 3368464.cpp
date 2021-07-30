#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define fr front()
#define bk back()
#define ppf pop_front()
#define tp top()
#define ps push
#define pp pop()

typedef unsigned long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

ll dp[2][100005] = {}, b[2][105] = {};

int main() {
    ll n, w;
    scanf("%lld%lld", &n, &w);
    for (ll i = 0; i < n; i++) {
        scanf("%lld%lld", &b[1][i], &b[0][i]);
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 1; j <= w; ++j) {
            dp[i & 1][j] = max(dp[i & 1][j - 1], dp[(i & 1) ^ 1][j]);
            if (j >= b[1][i]) {
                dp[i & 1][j] = max(dp[i & 1][j], dp[(i & 1) ^ 1][j - b[1][i]] + b[0][i]);
            }
        }
    }
    printf("%lld\n", dp[(n - 1) & 1][w]);
    return 0;
}