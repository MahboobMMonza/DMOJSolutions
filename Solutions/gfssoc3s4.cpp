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
#define sz size()
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

const ll mod = 1e9 + 7;

int r, c;

ll dp[100][3000]{};
vector<int> vd, adj[3000];

int main() {
    fio;
    cin >> r >> c;
    int m1, m2;
    ll ans = 0;
    for (int i = 0; i < 1<<(c-2); i++) {
        if (!(i & i>>1) && !(i&i>>2)) vd.pb(i);
    }
    for (int i = 0; i < vd.size(); i++) {
        m1 = vd[i];
        dp[0][i] = 1;
        ans++;
        for (int j = 0; j < vd.size(); j++) {
            m2 = vd[j] | vd[j] << 1 | vd[j] >> 1;
            if (!(m1 & m2)) adj[i].pb(j);
        }
    }
    ans -= dp[0][0];
    for (int ro = 1; ro < r - 1; ro++) {
        for (int i = 0; i < vd.sz; i++) {
            for (int j : adj[i]) { dp[ro][i] += dp[ro - 1][j]; }
            dp[ro][i] %= mod;
            ans = (ans + dp[ro][i]) % mod;
        }
        ans = (ans - dp[ro][0] + mod) % mod;
    }
    cout << ans << '\n';
    return 0;
}