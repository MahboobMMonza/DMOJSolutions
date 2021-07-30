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

ll dp[2005][2005][2]{};
vector<int> a;

int main() {
    fio;
    int n, p;
    cin >> n >> p;
    a.resize(n + 1);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[n] = p;
    n++;
    memset(dp, 0x3f, sizeof dp);
    sort(a.begin(), a.end());
    int s = lower_bound(a.begin(), a.end(), p) - a.begin();
    dp[s][s][0] = dp[s][s][1] = 0;
    for (int ln = 1; ln < n; ln++) {
        for (int l = 0; l + ln < n; l++) {
            int r = l + ln;
            dp[l][r][0] = min(dp[l + 1][r][0] + (ll (a[l + 1] - a[l])) * (n - ln), dp[l + 1][r][1] + (ll (a[r] - a[l])) * (n - ln));
            dp[l][r][1] = min(dp[l][r - 1][0] + (ll (a[r] - a[l])) * (n - ln), dp[l][r - 1][1] + (ll (a[r] - a[r - 1])) * (n - ln));
        }
    }
    cout << min(dp[0][n - 1][0], dp[0][n - 1][1]) << '\n';
    return 0;
}