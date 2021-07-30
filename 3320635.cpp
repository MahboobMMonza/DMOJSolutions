#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

priority_queue<pi, vector<pi>, greater<pi>> pq;
bitset<5001> v;

struct s{
    int c = -1, rc = -1;
    vector<pi> e;
} d[5001];

int main() {
    int n, m, a, b, w, mc = INT_MAX;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &a, &b, &w);
        d[a].e.emplace_back(b, w);
        d[b].e.emplace_back(a, w);
    }
    d[1].c = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        pi x = pq.top(); pq.pop();
        if (v[x.s]) continue;
        v[x.s] = 1;
        for (auto e : d[x.s].e) {
            if (!v[e.f] && (d[e.f].c == -1 || d[e.f].c > x.f + e.s)) {
                d[e.f].c = x.f + e.s;
                pq.push({d[e.f].c, e.f});
            }
        }
    }
    v.reset();
    d[n].rc = 0;
    pq.push({0, n});
    while (!pq.empty()) {
        pi x = pq.top(); pq.pop();
        if (v[x.s]) continue;
        v[x.s] = 1;
        for (auto e : d[x.s].e) {
            if (!v[e.f] && (d[e.f].rc == -1 || d[e.f].rc > x.f + e.s)) {
                d[e.f].rc = x.f + e.s;
                pq.push({d[e.f].rc, e.f});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto e : d[i].e) {
            if (d[i].c != -1 && d[e.f].rc != -1) {
                if (d[i].c + d[e.f].rc + e.s != d[n].c) {
                    mc = min(mc, d[i].c + d[e.f].rc + e.s);
                }
            }
        }
    }
    printf("%d\n", mc);
    return 0;
}