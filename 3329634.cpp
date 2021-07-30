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

typedef unsigned long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

bitset<200001> v;

// Town structure. Each town has it's own min level (l, cost of smallest large edge leading to town, -1 if impossible)
// ne points to latest outgoing edge, and t is the time needed to train at the town for 1 level (t is initialized in input)
// id is just node #
struct tg {
    ll l = -1, t;
    int ne = -1, id;

    friend bool operator<(tg const &a, tg const &b) {
        return (a.l == b.l) ? a.t > b.t : a.l > b.l;
    }

} g[200001];

// Road structure. Each road has origin (o), destination (d), min level (l), and point to next road for a certain town adjacency list (p)
struct r {
    int o, d;
    ll l;
    int p;
} e[400000];

int main() {
    priority_queue<tg, vector<tg>, less<tg>> pq;
    int n, m, a, b;
    ll t = 0, l, cl = 1;
    // Get and set all gym times, as well as set ids for all nodes
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        g[i].id = i;
        scanf("%lld", &g[i].t);
    }
    // Get all edges
    for (int i = 0; i < m; i++) {
        scanf("%d%d%lld", &a, &b, &l);
        e[2 * i] = {a, b, l, g[a].ne};
        e[(2 * i) ^ 1] = {b, a, l, g[b].ne};
        g[a].ne = 2 * i;
        g[b].ne = (2 * i) ^ 1;
    }
    // Set min level of first town to cl (current level = 1)
    g[1].l = 1;
    // Dijkstra implementation getting max edge cost for each town
    pq.ps(g[1]);
    while (!pq.empty()) {
        tg x = pq.tp;
        pq.pp;
        if (v[x.id]) continue;
        v[x.id] = 1;
        for (int i = x.ne; i != -1; i = e[i].p) {
            int ml = max(x.l, e[i].l);
            if (!v[g[e[i].d].id] && (g[e[i].d].l == -1 || g[e[i].d].l > ml)) {
                g[e[i].d].l = ml;
                pq.ps(g[e[i].d]);
            }
        }
    }
    // If town n cannot be reached print -1 and leave
    if (g[n].l == -1) {
        printf("-1\n");
        return 0;
    }
    // l used to hold cost of current level up time
    l = INT_MAX;
    // Add all reachable nodes to pq to see which gym is unlocked next and optimize level up cost
    for (int i = 1; i <= n; i++) {
        if (g[i].l != -1) pq.ps(g[i]);
    }
    // While current level is less than required level
    while (cl < g[n].l) {
        // While the current level is enough to reach next gym(s)
        while (cl >= pq.tp.l) {
            // Set l to lowest gym time and pop the town from pq
            l = min(pq.tp.t, l);
            pq.pp;
        }
        // Add time to level up to next gym availability level
        t += (pq.tp.l - cl) * l;
        // Just in case set current level to max level achieved so far, compared to next opening gym level
        cl = max(pq.tp.l, cl);
    }
    printf("%lld\n", t);
    return 0;
}