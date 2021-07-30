#include <bits/stdc++.h>

using namespace std;

#define fs first
#define fio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sc second
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ppb pop_back
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

int dp[505][5005]{}, v[505]{}, a[505]{};

int main() {
    fio;
    int T, N;
    cin >> T >> N;
    memset(a, -1, sizeof a);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= T; j++) {
            dp[i][j] = (j < v[i]) ? dp[i - 1][j] : max(dp[i - 1][j], dp[i - 1][j - v[i]] + v[i]);
        }
    }
    int n = N, t = T, va = 0;
    while (n && t) {
        if (dp[n][t] == dp[n - 1][t]) {
            n--;
        } else {
            t -= v[n];
            a[n] = t;
            n--;
        }
    }
    for (int i = 1; i <= N; ++i) {
        if (a[i] == -1) {
            a[i] = va;
            va += v[i];
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}