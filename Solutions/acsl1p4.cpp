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

int idx = 0, dfn[25]{}, low[25]{}, scc[25];
bool sm[25]{};
vector<vector<int>> adj(25);
st<int> dfs;

void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    dfs.ps(u);
    int a;
    sm[u] = 1;
    for (int & i : adj[u]) {
        if (!dfn[i]) {
            tarjan(i);
            low[u] = min(low[u], low[i]);
        } else if (sm[i]) {
            low[u] = min(low[u], dfn[i]);
        }
    }
    if (dfn[u] == low[u]) {
        do {
            a = dfs.tp;
            dfs.pp;
            sm[a] = 0;
        } while (a != u);
    }
}

int main() {
    fio;
    int n, k;
    cin >> n >> k;
    for (int i = 1,a, b, c, d; i <= k; i++) {
        cin >> a >> b >> c >> d;
        if (c > d) adj[a].pb(b);
        else adj[b].pb(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
        scc[low[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (scc[i] > 1) ans += scc[i];
    }
    cout << ans << '\n';
    return 0;
}