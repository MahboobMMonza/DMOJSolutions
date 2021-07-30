#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(1000001);
int g[1001][1001];
bitset<1000001> v;
queue<int> q;
int main() {
    int m, n, x;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &g[i][j]);
            adj[i * j].emplace_back(g[i][j]);
        }
    }
    q.push(g[1][1]);
    v[g[1][1]] = 1;
    while (!q.empty()) {
        x = q.front(); q.pop();
        for (int e : adj[x]) {
            if (!v[e]) {
                q.push(e);
                v[e] = 1;
            }
        }
    }
    printf("%s", v[m * n] ? "yes" : "no");
    return 0;
}