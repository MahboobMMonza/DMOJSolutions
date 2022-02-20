#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second


typedef pair<int, int> pii;

vector<pii> adj[2001];
priority_queue<pii, vector<pii>, greater<pii>> pq;
unordered_set<int> vis;

int d[2001] = {0};

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
    d[b] = 0;
    pq.push({0, b});
    while (!pq.empty()) {
        c = pq.top();
        pq.pop();
        vis.insert(c.s);
        for (int i = 0; i < adj[c.s].size(); i++) {
            pii p = adj[c.s][i];
            if (!vis.count(p.f)) {
                if (d[p.f] == -1 || d[p.f] > d[c.s] + p.s) {
                    d[p.f] = d[c.s] + p.s;
                    pq.push({d[p.f], p.f});
                }
            }
        }
    }
    while (q--) {
        scanf("%d", &a);
        printf("%d\n", d[a]);
    }
    return 0;
}