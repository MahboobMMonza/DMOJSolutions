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

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

ll dp[100005] = {};


// flip to find min weight for value (coin problem with 1 coin each)
int main() {
    ll n, W, v, w, mv = (ll) 1e5 + 1;
    memset(dp, 0x3f, sizeof dp);
    scanf("%lld%lld", &n, &W);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &w, &v);
        for (ll j = mv - 1; j >= v; j--) {
            dp[j] = min(dp[j], dp[j - v] + w);
        }
    }
    for (ll i = mv - 1; i >= 0; i--) {
        if (dp[i] <= W) {
            printf("%lld", i);
            return 0;
        }
    }
}