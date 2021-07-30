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

struct s {
    int c = -1, rc = -1;
    vector<pi> e, re;
} d[20001];

int main() {
    int n, m, a, b, w, mc = -1;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &a, &b, &w);
        d[a].e.emplace_back(b, w);
        d[b].re.emplace_back(a, w);
    }
    d[1].c = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        pi x = pq.top();
        pq.pop();
        if (d[x.s].c < x.f) continue;
        for (auto e : d[x.s].e) {
            if (d[e.f].c == -1 || d[e.f].c > x.f + e.s) {
                d[e.f].c = x.f + e.s;
                pq.push({d[e.f].c, e.f});
            }
        }
    }
    d[n].rc = 0;
    pq.push({0, n});
    while (!pq.empty()) {
        pi x = pq.top();
        pq.pop();
        if (d[x.s].rc < x.f) continue;
        for (auto e : d[x.s].re) {
            if (d[e.f].rc == -1 || d[e.f].rc > x.f + e.s) {
                d[e.f].rc = x.f + e.s;
                pq.push({d[e.f].rc, e.f});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto e : d[i].e) {
            if (d[i].c != -1 && d[e.f].rc != -1) {
                if (d[i].c + d[e.f].rc + e.s != d[n].c) {
                    mc = (mc == -1) ? d[i].c + d[e.f].rc + e.s : min(mc, d[i].c + d[e.f].rc + e.s);
                }
            }
        }
    }
    printf("%d", mc);
    return 0;
}