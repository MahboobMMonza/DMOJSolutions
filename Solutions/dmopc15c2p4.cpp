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

vector<pll> a; // {end, {start, happy}}


ll dp[(int)1e5 + 2];
int main() {
    fio;
    ll n;
    cin >> n;
    a.pb({0,{0,0}});
    for (ll i = 0, r, l, h; i < n; i++) {
        cin >> r >> l >> h;
        a.pb({r + l, {r, h}});
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++) {
        int p = upper_bound(a.begin(), a.begin() + i, (pll) {a[i].sc.fs, a[i].sc}) - a.begin() - 1;
        dp[i] = max(dp[i - 1], a[i].sc.sc + dp[p]);
    }
    cout << dp[n] << '\n';
    return 0;
}