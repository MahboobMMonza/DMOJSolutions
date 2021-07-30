#include <bits/stdc++.h>

using namespace std;

#define fs first
#define fio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sc second
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ppb pop_back()
#define fr front()
#define bk back()
#define sbf setbuf(stdout, 0)
#define ppf pop_front()
#define tp top()
#define ps push
#define pp pop()
#define fls fflush(stdout)
#define qu queue
#define st stack
#define pq priority_queue
typedef unsigned long long ull;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pl;
typedef pair<ull, ull> pull;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;
typedef pair<pi, pi> ppi;
typedef pair<char, int> pci;

const ll PRIME = 9223372036854775783, BASE = 26;

inline ll mulMod(ll x, ll y, ll m = LONG_LONG_MAX) {
    x %= m;
    ll res = 0;
    while (y) {
        if (y & 1) res = (res + x) % m;
        if (res < 0) res += m;
        x = (x << 1) % m;
        y >>= 1;
    }
    return res % m;
}

inline ll logPow(ll x, ll y, ll m = LONG_LONG_MAX) {
    x %= m;
    ll res = 1;
    while (y) {
        if (y & 1) res = mulMod(res, x, m);
        x = mulMod(x, x, m);
        y >>= 1;
    }
    return res % m;
}

inline ll pLogPow(ll x, ll y, ll m = 9223372036854775783) { return logPow(x, y % (m - 1), m); }

ll dp[2][5005]{};

int main() {
    fio;
    int N, H, q, g, h, t;
    cin >> N >> H;
    for (int n = 1; n <= N; n++) {
        cin >> g >> h >> q >> t;
        for (int i = 0; i <= H; i++) {
            dp[n & 1][i] = (i < h) ? 0 : dp[(n ^ 1) & 1][i - h] + g;
        }
        for (int i = h; i + t <= H; i++) {
            dp[n & 1][i + t] = max(dp[n & 1][i + t], dp[n & 1][i] + q);
        }
        for (int i = 1; i <= H; i++) {
            dp[n & 1][i] = max(dp[n & 1][i], dp[(n ^ 1) & 1][i]);
        }
    }
    cout << dp[N & 1][H] << '\n';
    return 0;
}