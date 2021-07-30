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

 vector<int> adj[200'005]{};
set<int> vips;
int l[2][200005]{};
bitset<200005> vis[2];

void bfs(int a, int n, int k) {
    qu<pi> q;
    q.emplace(a, 0);
    while (!q.empty()) {
        pi x = q.fr; q.pp;
        for (int w : adj[x.fs]) {
            if (!vis[a / n][w]) {
                l[a / n][w] = x.sc + 1;
                vis[a / n][w] = 1;
                if (l[a / n][w] <= k && vis[!(a / n)][w] && l[!(a / n)][w] <= k) {
                    vips.insert(w);
                }
                q.ps({w, x.sc + 1});
            }
        }
    }
}

int main() {
    fio;
    int n, m, k;
    cin >> n >> m >> k;
    vips.insert(1);
    vips.insert(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    bfs(1, n, k); bfs(n, n, k);
    ll c = vips.size() - 2;
    cout << pLogPow(2, c, 1000000007) << '\n';
    return 0;
}