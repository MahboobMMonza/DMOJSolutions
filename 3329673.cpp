#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define fr front()
#define bk back()
#define ppf pop_front()
#define tp top()
#define ps push
#define pp pop()

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

bitset<200001> v;

struct tg {
    ll l = -1, t;
    int ne = -1, id;

    friend bool operator<(tg const &a, tg const &b) {
        return (a.l == b.l) ? a.t > b.t : a.l > b.l;
    }

} g[200001];

struct r {
    int o, d;
    ll l;
    int p;
} e[400000];

int main() {
    priority_queue<tg, vector<tg>, less<tg>> pq;
    int n, m, a, b;
    ll t = 0, l, cl = 1;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        g[i].id = i;
        scanf("%lld", &g[i].t);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d%lld", &a, &b, &l);
        e[2 * i] = {a, b, l, g[a].ne};
        e[(2 * i) ^ 1] = {b, a, l, g[b].ne};
        g[a].ne = 2 * i;
        g[b].ne = (2 * i) ^ 1;
    }
    g[1].l = 1;
    pq.ps(g[1]);
    while (!pq.empty()) {
        tg x = pq.tp;
        pq.pp;
        if (v[x.id]) continue;
        v[x.id] = 1;
        for (int i = x.ne; i != -1; i = e[i].p) {
            ll ml = max(x.l, e[i].l);
            if (!v[g[e[i].d].id] && (g[e[i].d].l == -1ll || g[e[i].d].l > ml)) {
                g[e[i].d].l = ml;
                pq.ps(g[e[i].d]);
            }
        }
    }
    if (g[n].l == -1) {
        printf("-1\n");
        return 0;
    }
    l = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (g[i].l != -1ll) pq.ps(g[i]);
    }
    while (cl < g[n].l) {
        if (cl >= pq.tp.l) {
            l = min(pq.tp.t, l);
            pq.pp;
        }
        else {
            t += (pq.tp.l - cl) * l;
            cl = pq.tp.l;
        }
    }
    printf("%lld\n", t);
    return 0;
}