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

bitset<16000001> vis;

struct e{
    int h, ne;
} adj[16000001];

int head[16000001] = {0};

bool can_escape(int M, int N, vector<vector<int>> v) {
    memset(head, -1, sizeof(head));
    int c  = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            adj[c] = {v[i][j], head[i * j]};
            head[i * j] = c;
            c++;
        }
    }
    queue<int> q;
    q.ps(v[1][1]);
    vis[v[1][1]] = 1;
    while (!q.empty()) {
        int x = q.fr; q.pp;
        for (int i = head[x]; i != -1; i = adj[i].ne) {
            if (!vis[adj[i].h]) {
                q.ps(adj[i].h);
                vis[adj[i].h] = 1;
                if (vis[M * N]) return 1;
            }
        }
    }
    return 0;
}