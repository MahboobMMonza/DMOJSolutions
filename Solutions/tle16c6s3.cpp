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


ll dp[2002][2002][2]{}, psa[2002]{};
pl a[2002];

int main() {
    fio;
    int n;
    ll ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fs >> a[i].sc;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        psa[i] = psa[i - 1] + a[i].sc;
        if (a[i].fs == 0) dp[i][i][0] = dp[i][i][1] = a[i].sc;
    }
    for (int ln = 1; ln < n; ln++) {
        for (int l = 1; l + ln <= n; l++) {
            int r = l + ln;
            if (dp[l + 1][r][0] >= a[l + 1].fs - a[l].fs)
                dp[l][r][0] = max(dp[l][r][0], dp[l + 1][r][0] + a[l].sc - (a[l + 1].fs - a[l].fs));
            if (dp[l + 1][r][1] >= a[r].fs - a[l].fs)
                dp[l][r][0] = max(dp[l][r][0], dp[l + 1][r][1] + a[l].sc - (a[r].fs - a[l].fs));
            if (dp[l][r - 1][1] >= a[r].fs - a[r - 1].fs)
                dp[l][r][1] = max(dp[l][r][1], dp[l][r - 1][1] + a[r].sc - (a[r].fs - a[r - 1].fs));
            if (dp[l][r - 1][0] >= a[r].fs - a[l].fs)
                dp[l][r][1] = max(dp[l][r][1], dp[l][r - 1][0] + a[r].sc - (a[r].fs - a[l].fs));
        }
    }
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            if (dp[l][r][0] > 0 || dp[l][r][1] > 0) ans = max(ans, psa[r] - psa[l - 1]);
        }
    }
    cout << ans << '\n';
    return 0;
}