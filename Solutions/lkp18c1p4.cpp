#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

vector<vector<pll>> adj(100001);

ll ds(int a, int b, int k, ll c) {
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    bitset<100001> v;
    ll d[100001] = {0};
    pq.push({0, a});
    while (!pq.empty()) {
        pl x = pq.top(); pq.pop();
        if (v[x.s]) continue;
        v[x.s] = 1;
        if (x.s == b) {
            return (d[b] < c) ? d[b] : -1;
        }
        for (auto e : adj[x.s]) {
            if (!v[e.f] && e.s.s <= k) {
                d[e.f] = (d[e.f]) ? min(x.f + e.s.f, d[e.f]) : x.f + e.s.f;
                pq.push({d[e.f], e.f});
            }
        }
    }
    return -1;
}


int main() {
    int n, m, a, b, l = 1, h, k, mk = -1;
    ll d, c;
    scanf("%d%d", &n, &m);
    h = m;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%lld", &a, &b, &c);
        adj[a].push_back({b, {c, i}});
        adj[b].push_back({a, {c, i}});
    }
    scanf("%d%d%lld", &a, &b, &c);
    while (l <= h) {
        k = (l + h) / 2;
        d = ds(a, b, k, c);
        if (d == -1) {
            l = k + 1;
        } else {
            mk = k;
            h = k - 1;
        }
    }
    printf("%d", mk);
    return 0;
}