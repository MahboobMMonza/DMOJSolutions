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

int p[305]{}, dp[305][305]{};

int main() {
    fio;
    int n;
    cin >> n;
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        dp[i][i] = 1;
    }
    for (int ln = 1; ln < n; ln++) {
        for (int l = 1; l + ln <= n; l++) {
            int r = l + ln;
            for (int m = l; m < r; m++) {
                dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r]);
            }
            if (p[l] == p[r]) dp[l][r] = min(dp[l][r - 1], dp[l + 1][r]);
        }
    }
    cout << dp[1][n] << '\n';
    return 0;
}