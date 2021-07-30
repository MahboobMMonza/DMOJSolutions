#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second


typedef pair<int, int> pii;

vector<pii> adj[2001];
priority_queue<pii, vector<pii>, greater<pii>> pq;
unordered_set<int> vis;

int d[2001][2001] = {0};
int main() {
    int n, m, b, q, x, y, z, a;
    pii c;
    memset(d, -1, sizeof(d));
    scanf("%d%d%d%d", &n, &m, &b, &q);
    while (m--) {
        scanf("%d%d%d", &x, &y, &z);
        adj[x].emplace_back(y, z);
        adj[y].emplace_back(x, z);
    }
    while (q--) {
        scanf("%d", &a);
        d[a][a] = 0;
        pq = {};
        vis = {};
        pq.push({0, a});
        while (!pq.empty()) {
            c = pq.top();
            pq.pop();
            if (vis.count(c.s)) continue;
            vis.insert(c.s);
            if (c.s == b) break;
            for (int i = 0; i < adj[c.s].size(); i++) {
                pii p = adj[c.s][i];
                if (!vis.count(p.f)) {
                    if (d[a][p.f] == -1 || d[a][p.f] > d[a][c.s] + p.s) {
                        d[a][p.f] = d[a][c.s] + p.s;
                        
                            pq.push({d[a][p.f], p.f});
                        
                    }
                }
            }
        }
        printf("%d\n", d[a][b]);
    }
    return 0;
}