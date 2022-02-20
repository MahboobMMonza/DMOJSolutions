#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
typedef pair<int,int> pii;
bitset<2001> iq;
int d[2001][201] = {0};
struct sr{int isl, t, d;};
vector<vector<sr>> adj(2001);
priority_queue<pii, vector<pii>, greater<pii>> pq;
int main() {
    memset(d, CHAR_MAX, sizeof(d));
    int n, m, k, a, b, t, h, x, nt, bt = 2139062143;
    scanf("%d%d%d",&k, &n, &m);
    while (m--) {
        scanf("%d%d%d%d", &a, &b, &t, &h);
        adj[a].push_back({b, t, h});
        adj[b].push_back({a, t, h});
    }
    scanf("%d%d", &a, &b);
    d[a][0] = 0;
    iq[a] = 1;
    pq.push({0, a});
    while (!pq.empty()) {
        x = pq.top().s; pq.pop();
        iq[x] = 0;
        for (int i = 0; i < adj[x].size(); i++) {
            for (int j = 0; j + adj[x][i].d < k; j++) {
                 nt = d[x][j] + adj[x][i].t;
                 if (nt < d[adj[x][i].isl][j + adj[x][i].d]) {
                     d[adj[x][i].isl][j + adj[x][i].d] = nt;
                     if (!iq[adj[x][i].isl]) {
                         iq[adj[x][i].isl] = 1;
                         pq.push({nt, adj[x][i].isl});
                     }
                 }
            }
        }
    }
    for (int i = 0; i < k; i++) {
        bt = min(bt, d[b][i]);
    }
    printf("%d", (bt == 2139062143) ? -1 : bt);
    return 0;
}