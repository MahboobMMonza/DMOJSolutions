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

vector<pl> ap;
ll dp[2][200005]{};

ll bs(ll k, ll x) {
    ll l = 0, h = k, ans = 0;
    while (l <= h) {
        int m = (h - l) / 2 + l;
        if (ap[m].fs <= x) {
            ans = m;
            l = m + 1;
        } else h = m - 1;
    }
    return ans;
}

int main() {
    fio;
    ll n, k, a, b;
    cin >> n >> k;
    ap.eb(0,0);
    for (int i = 1; i <= k; i++) {
        cin >> a >> b;
        ap.eb(b, a);
    }
    sort(ap.begin(), ap.end());
    for (int i = 1; i <= k; i++) {
        dp[0][i] = bs(k, ap[i].sc);
    }
    for (int i = 1; i <= k; i++) {
        dp[1][i] = max(dp[1][i - 1], ap[i].fs - ap[i].sc + 1 + dp[1][dp[0][i]]);
    }
    cout << n - dp[1][k] << '\n';
    return 0;
}