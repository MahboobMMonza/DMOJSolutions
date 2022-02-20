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

int dp[75][75][75]{}, psa[75], n, k;
bool v[75][75][75]{};
pii apf[75];

bool cmpP(pii const & x, pii const & y) {
    return x.sc.fs < y.sc.fs;
}

bool cmpK(pii const & x, pii const & y) {
    return x.fs < y.fs;
}

int fn(int l, int r, int w) {
    // try to root at m and compare costs
    if (l > r) return 0;
    if (v[l][r][w]) return dp[l][r][w];
    v[l][r][w] = 1;
    int ans = INT_MAX, s = psa[r] - psa[l - 1];
    for (int m = l; m <= r; m++) {
        ans = min(ans, fn(l, m - 1, w) + fn(m + 1, r, w) + s + k);
        if (apf[m].sc.fs >= w) ans = min(ans, fn(l, m - 1, apf[m].sc.fs) + fn(m + 1, r, apf[m].sc.fs) + s);
    }
    return dp[l][r][w] = ans;
}

int main() {
    fio;
    // reading inputs
    cin >> n >> k;
    // keys
    for (int i = 1; i <= n; i++) {
        cin >> apf[i].fs;
    }
    // priority
    for (int i = 1; i <= n; i++) {
        cin >> apf[i].sc.fs;
    }
    // frequency
    for (int i = 1; i <= n; i++) {
        cin >> apf[i].sc.sc;
    }
    // sort by priority and compress (1 < 100 < 200 will be considered same as 1 < 2 < 3)
    sort(apf + 1, apf + n + 1, cmpP);
    for (int i = 1; i <= n; i++) {
        apf[i].sc.fs = i;
    }
    // sort by key for psa and compress
    sort(apf + 1, apf + n + 1, cmpK);
    for (int i = 1; i <= n; i++) {
        apf[i].fs = i;
    }
    // psa
    for (int i = 1; i <= n; i++) psa[i] = psa[i - 1] + apf[i].sc.sc;
    cout << fn(1, n, 0) << '\n';
    return 0;
}