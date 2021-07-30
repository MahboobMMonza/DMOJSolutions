#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

bitset<500001> v;

struct b {
    int c = -1, rc = -1;
    vector<pi> e, re;
} bl[500001];
vector<pii> cd;
priority_queue<pi, vector<pi>, greater<pi>> pq;

int main() {
    int n, m, d, a, b, w, c;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &a, &b, &w);
        bl[a].e.emplace_back(b, w);
        bl[b].re.emplace_back(a, w);
    }
    scanf("%d", &d);
    for (int i = 0; i < d; i++) {
        scanf("%d%d%d", &a, &b, &w);
        cd.push_back({a, {b, w}});
    }
    bl[1].c = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        pi x = pq.top();
        pq.pop();
        if (v[x.s]) continue;
        v[x.s] = 1;
        for (auto i : bl[x.s].e) {
            if (!v[i.f]) {
                bl[i.f].c = (bl[i.f].c == -1) ? x.f + i.s : min(x.f + i.s, bl[i.f].c);
                pq.push({bl[i.f].c, i.f});
            }
        }
    }
    v.reset();
    bl[n].rc = 0;
    pq.push({0, n});
    while (!pq.empty()) {
        pi x = pq.top();
        pq.pop();
        if (v[x.s]) continue;
        v[x.s] = 1;
        for (auto i : bl[x.s].re) {
            if (!v[i.f]) {
                bl[i.f].rc = (bl[i.f].rc == -1) ? x.f + i.s : min(x.f + i.s, bl[i.f].rc);
                pq.push({bl[i.f].rc, i.f});
            }
        }
    }
    c = bl[n].c;
    for (int i = 0; i < d; i++) {
        if (bl[cd[i].f].c != -1 && bl[cd[i].s.f].rc != -1) {
            c = (c == -1) ? bl[cd[i].f].c + cd[i].s.s + bl[cd[i].s.f].rc : min(c, bl[cd[i].f].c + cd[i].s.s + bl[cd[i].s.f].rc);
        }
    }
    printf("%d\n", c);
    return 0;
}