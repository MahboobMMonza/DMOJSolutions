#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
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
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

struct e {
    int b, n;
    ll t;
} adj[600005] = {};

struct c {
    ll d[2] {0x3f3f3f3f, 0x3f3f3f3f};
    int h = -1;
} ct[100005];

bitset<100005> v;

void dks(int s, int r) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    v.reset();
    ct[s].d[r] = 0;
    pq.ps({0, s});
    while (!pq.empty()) {
        pi x = pq.tp; pq.pp;
        if (v[x.sc]) continue;
        v[x.sc] = 1;
        for (int i = ct[x.sc].h; i != -1; i = adj[i].n) {
            if (!v[adj[i].b] && ct[adj[i].b].d[r] > x.fs + adj[i].t) {
                ct[adj[i].b].d[r] = x.fs + adj[i].t;
                pq.ps({ct[adj[i].b].d[r], adj[i].b});
            }
        }
    }
}

int main() {
    int N, M, a, b;
    ll t, ans = -1;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < 2 * M; i += 2) {
        scanf("%d%d%lld", &a, &b, &t);
        adj[i] = {b, ct[a].h, t};
        adj[i ^ 1] = {a, ct[b].h, t};
        ct[a].h= i;
        ct[b].h = i ^ 1;
    }
    dks(0, 0);
    dks(N - 1, 1);
    for (int i = 0; i < N; i++) {
        ans = max(ans, ct[i].d[0] + ct[i].d[1]);
    }
    printf("%lld\n", ans);
    return 0;
}