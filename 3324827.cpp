#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

struct h {
    int c = -1, d = INT_MAX, id = -1;
    bool v = 0;
    vector<pi> e;

    friend bool operator > (h const& a, h const& b) {
        return (a.d == b.d) ? a.c > b.c : a.d > b.d;
    }

} l[100001];

int main() {
    priority_queue<h, vector<h>, greater<h>> pq;
    int n, m, x, y, z;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &x, &y, &z);
        l[x].e.emplace_back(y, z);
        l[y].e.emplace_back(x, z);
    }
    l[1].c = 0; l[1].d = 0;
    l[n].id = n;
    pq.push(l[1]);
    while (!pq.empty()) {
        h a = pq.top(); pq.pop();
        if (a.v) continue;
        a.v = 1;
        if (a.id == n) {
            printf("%d %d\n", a.d, a.c);
            return 0;
        }
        for (auto r : a.e) {
            if (l[r.f].c == -1 || l[r.f].d > a.d + r.s || (l[r.f].d == a.d && l[r.f].c > a.c + 1)) {
                l[r.f].c = a.c + 1;
                l[r.f].d = a.d + r.s;
                pq.push(l[r.f]);
            }
        }
    }
    printf("-1\n");
    return 0;
}