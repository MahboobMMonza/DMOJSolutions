#include <bits/stdc++.h>

using namespace std;

#define fs first
#define fio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sc second
#define pb push_back
#define eb emplace_back
#define edl '\n'
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

ll costs[5003];
vector<pi> adj[5003];
bool vis[5003];

void spfa(int n, int dest) {
    int cur;
    costs[n] = 0;
    deque<int> q;
    q.pb(n);
    vis[n] = 1;
    while (!q.empty()) {
        cur = q.fr;
        q.ppf;
        vis[cur] = 0;
        for (size_t i = 0; i < adj[cur].size(); ++i) {
            if (costs[adj[cur][i].fs] > costs[cur] + (ll) adj[cur][i].sc) {
                costs[adj[cur][i].fs] = costs[cur] + (ll) adj[cur][i].sc;
                if (!vis[adj[cur][i].fs]) {
                    (q.empty() || costs[q.fr] > costs[adj[cur][i].fs]) ? q.pf(adj[cur][i].fs) :
                    q.pb(adj[cur][i].fs);
                    vis[adj[cur][i].fs] = 1;
                }
            }
        }
    }
}

int main() {
    fio;
    fill(costs, costs + 5001, LONG_LONG_MAX);
    fill(vis, vis + 5001, false);
    int n, t, k, x, y, d;
    int c;
    cin >> n >> t;
    while (t--) {
        cin >> x >> y >> c;
        adj[x - 1].emplace_back(y - 1, c);
        adj[y - 1].emplace_back(x - 1, c);
    }
    cin >> k;
    while (k--) {
        cin >> y >> c;
        adj[n].emplace_back(y - 1, c);
    }
    cin >> d;
    d--;
    spfa(n, d);
    cout << costs[d] << edl;
}