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

ll dp[205][205]{};
const ll MOD = 1e5;
string s;

int p(char l, char r) {
    if (((l == '(' || l == '[' || l == '{') && r == '?') || ((r == ')' || r == ']' || r == '}') && l == '?') || (l == '(' && r == ')') || (l == '[' && r == ']') || (l == '{' && r == '}')) return 1;
    return (l == r && r == '?') ? 3 : 0;
}

ll fn(int l, int r) {
    if (l >= r) return 1;
    if (dp[l][r] != - 1) return dp[l][r];
    ll &ret = dp[l][r]; ret = 0;
    for (int m = l + 1; m <= r; m += 2) {
        ret = ret + fn(l + 1, m - 1) * fn(m + 1, r) * p(s[l], s[m]);
        if (ret >= MOD) ret = ret % MOD + MOD;
    }
    return ret;
}

int main() {
    fio;
    int n;
    cin >> n >> s;
    memset(dp, - 1, sizeof dp);
    ll ans = fn(0, n - 1);
    if (ans >= MOD) cout << setw(5) << setfill('0') << ans % MOD << '\n';
    else cout << ans << '\n';
    return 0;
}