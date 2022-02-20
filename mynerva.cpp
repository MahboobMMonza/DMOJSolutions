#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

struct isl {
    int wc = -1, bc = -1, b = 0, bb = 0;
    bool wv = 0, bv = 0;
    vector<pi> e;

    // Maximize brightness
    friend bool operator < (isl const& a, isl const& b) {
        return (a.wc == b.wc) ? a.b < b.b : a.wc > b.wc;
    }

    // Minimize brightness
    friend bool operator > (isl const& a, isl const& b) {
        return (a.bc == b.bc) ? a.bb > b.bb : a.bc > b.bc;
    }

} l[500001];

char c[6];
int main() {
    priority_queue<isl, vector<isl>, less<isl>> wpq;
    priority_queue<isl, vector<isl>, greater<isl>> bpq;
    int n, m, x, y, q, z, d;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &x, &y, &z);
        l[x].e.emplace_back(y, z);
        l[y].e.emplace_back(x, z);
    }
    l[1].wc = l[1].bc = 0;
    wpq.push(l[1]);
    while (!wpq.empty()) {
        isl a = wpq.top(); wpq.pop();
        if (a.wv) continue;
        a.wv = 1;
        for (auto r : a.e) {
            if (l[r.f].wc == -1 || l[r.f].wc > a.wc + 1 || (l[r.f].wc == a.wc + 1 && l[r.f].b < a.b + r.s)) {
                l[r.f].wc = a.wc + 1;
                l[r.f].b = a.b + r.s;
                wpq.push(l[r.f]);
            }
        }
    }
    bpq.push(l[1]);
    while (!bpq.empty()) {
        isl a = bpq.top(); bpq.pop();
        if (a.bv) continue;
        a.bv = 1;
        for (auto r : a.e) {
            if (l[r.f].bc == -1 || l[r.f].bc > a.bc + 1 || (l[r.f].bc == a.bc + 1 && l[r.f].bb > a.bb + r.s)) {
                l[r.f].bc = a.bc + 1;
                l[r.f].bb = a.bb + r.s;
                bpq.push(l[r.f]);
            }
        }
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d%s", &d, c);
        (!strcmp(c, "White")) ? printf("%d %d\n", l[d].wc, l[d].b) : printf("%d %d\n", l[d].bc, l[d].bb);
    }
    return 0;
}