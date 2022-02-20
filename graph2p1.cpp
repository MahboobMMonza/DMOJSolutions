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

int n, idx = 0, dfn[1005]{}, low[1005]{};
bool g[1005][1005]{}, sm[1005]{};
vector<vector<int>> px(1005);
st<int> dfs;

void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    int a = 0;
    dfs.ps(u);
    sm[u] = 1;
    for (int i = 1; i <= n; i++) {
        if (i == u) continue;
        if (!dfn[i] && g[u][i]) {
            tarjan(i);
            low[u] = min(low[u], low[i]);
        } else if (sm[i]) {
            low[u] = min(low[u], dfn[i]);
        }
    }
    if (dfn[u] == low[u]) {
        do {
            sm[dfs.tp] = 0;
            a = dfs.tp;
            dfs.pp;
        } while (a != u);
    }
}

int main() {
    fio;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1, x; j <= n; j++) {
          cin >> x;
          g[i][j] = (bool) x;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= n; i++) {
        px[low[i]].pb(i);
    }
    for (int i = 1; i <= n; i++) {
        if (!px[i].empty()) {
            for(auto & x : px[i]) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}