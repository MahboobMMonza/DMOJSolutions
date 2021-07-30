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

bool v[1505][1505];
int n, m, psa[1505][1505]{};

char g[1505][1505];

bool bfs(int x) {
    qu<pi> q;
    pi c;
    int mv[8] = {0, 1, 0, -1, 1, 0, -1, 0};
    memset(v, 0, sizeof v);
    if (psa[x][x] - psa[0][x] - psa[x][0] + psa[0][0] == 0) {
        q.ps({1, 1});
        v[1][1] = 1;
    }
    while (!q.empty()) {
        c = q.fr;
        q.pp;
        for (int k = 0; k < 8; k += 2) {
            if (c.fs + mv[k] > 0 && c.fs + x + mv[k] - 1 <= n && c.sc + mv[k + 1] > 0
                && c.sc + mv[k + 1] - 1 <= m && !v[c.fs + mv[k]][c.sc + mv[k + 1]]
                && psa[c.fs + mv[k] + x - 1][c.sc + mv[k + 1] + x - 1] -
                psa[c.fs + mv[k] - 1][c.sc + mv[k + 1] + x - 1] -
                psa[c.fs + x + mv[k] - 1][c.sc + mv[k + 1] - 1] + psa[c.fs + mv[k] - 1][c.sc + mv[k + 1] - 1] == 0) {
                q.ps({c.fs + mv[k], c.sc + mv[k + 1]});
                v[c.fs + mv[k]][c.sc + mv[k + 1]] = 1;
            }
        }
    }
    return v[n - x + 1][m - x + 1];
}

int main() {
    fio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'X') psa[i][j]++;
            psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
        }
    }
    int l = 0, r = min(n, m), a = l;
    while (l <= r) {
        int md = (r - l) / 2 + l;
        if (bfs(md)) {
            a = md;
            l = md + 1;
        } else r = md - 1;
    }
    cout << a << '\n';
    return 0;
}