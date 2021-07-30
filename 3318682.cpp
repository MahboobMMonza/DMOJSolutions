#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long ll;
typedef pair<int, ll> pi;
typedef pair<int, pi> pii;

// Kruskal edges
pii e[200005];

bitset<200005> vis;

// Adjacency list
vector<pi> adj[200005];

// Kruskal dfs
stack<int> dfs;

// c for cost, dj for disjoint set
int c[200005] = {0}, dj[200005] = {0};

// Kruskal MAX spanning tree comparison. For min swap operation sign
bool cmp(pii const& a, pii const& b) {return a.s.s > b.s.s;}

// Disjoint set parent finding for cycle
int find(int d) {
    return (dj[d] == d) ? dj[d] : dj[d] = find(dj[d]);
}

int main() {
    int n, m, u, v, w, co = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
         e[i] = { u, {v, w}};
    }
    // Sort all edges
    sort(e, e + m, cmp);
    // All parent disjoint sets are themselves
    for (int i = 1; i <= n; i++) dj[i] = i;
    // Check each next largest edge
    for (int i = 0; i < m; i++) {
        // If no cycle is formed (parents are not the same at the current run of the set)
        if (find(e[i].f) != find(e[i].s.f)) {
            // Add the current edge to the set of the parent
            dj[find(e[i].f)] = find(e[i].s.f);
            // The adding is done n - 1 times so that there are n - 1 edges (for n nodes)
            co++;
            // Add shortest edges to adjacency list for dfs
            adj[e[i].f].push_back(e[i].s);
            adj[e[i].s.f].emplace_back(e[i].f, e[i].s.s);
        }
        // N - 1 edges
        if (co == n - 1) break;
    }
    // Dfs because edges are all sorted
    c[1] = 1e9;
    dfs.push(1);
    while (!dfs.empty()) {
        int x = dfs.top(); dfs.pop();
        vis[x] = 1;
        for (pi a : adj[x]) {
            if (!vis[a.f]) {
                c[a.f] = min((ll) c[x], a.s);
                dfs.push(a.f);
            }
        }
    }
    c[1] = 0;
    for (int i = 1; i <= n; i++) {
        printf("%d\n", c[i]);
    }
    return 0;
}