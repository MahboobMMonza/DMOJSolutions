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

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

bitset<100001> v;

struct r {
    int x, y, l, c, p;

} rd[200000];

struct cr {
    int d, c;
    bool operator < (cr const& a) const {
        return this->d < a.d;
    }
};

vector<cr> st;

struct ct {
    int d = -1, dr = -1, ne = -1, nre = -1;
} o[100001];


int sa[100001] = {0};

void spfa(int a) {
    o[a].d = 0;
    deque<int> q;
    q.pb(a);
    v[a] = 1;
    while (!q.empty()) {
        int p = q.fr; q.ppf;
        v[p] = 0;
        ct c = o[p];
        for (int i = c.ne; i != -1; i = rd[i].p) {
            r e = rd[i];
            if (o[e.y].d == -1 || o[e.y].d > c.d + e.l) {
                o[e.y].d = e.l + c.d;
                if (!v[e.y]) {
                    (q.empty() || o[q.fr].d > o[e.y].d) ? q.pf(e.y) : q.pb(e.y);
                    v[e.y] = 1;
                }
            }
        }
    }
}

void rspfa(int a) {
    v.reset();
    o[a].dr = 0;
    deque<int> q;
    q.pb(a);
    v[a] = 1;
    while (!q.empty()) {
        int p = q.fr; q.ppf;
        v[p] = 0;
        ct c = o[p];
        for (int i = c.nre; i != -1; i = rd[i].p) {
            r e = rd[i];
            if (o[e.x].dr == -1 || o[e.x].dr > c.dr + e.l) {
                o[e.x].dr = e.l + c.dr;
                if (!v[e.x]) {
                    (q.empty() || o[q.fr].dr > o[e.x].dr) ? q.pf(e.x) : q.pb(e.x);
                    v[e.x] = 1;
                }
            }
        }
    }
}
int main() {
    int n, m, a, b, q, x, y, l, c, md, d, h;
    scanf("%d%d%d%d", &n, &m, &a, &b);
    for (int i = 0; i < 2 * m; i += 2) {
        scanf("%d%d%d%d", &x, &y, &l, &c);
        rd[i] = {x, y, l, c, o[x].ne};
        rd[i ^ 1] = {x, y, l, c, o[y].nre};
        o[x].ne = i;
        o[y].nre = i ^ 1;
    }
    spfa(a);
    rspfa(b);
    for (int i = 0; i < 2 * m; i += 2) {
        if (o[rd[i].x].d != -1 && o[rd[i].y].dr != -1) {
            st.pb({o[rd[i].x].d + o[rd[i].y].dr + rd[i].l, rd[i].c});
        }
    }
    sort(st.begin(), st.end());
    c = 1;
    for (auto & i : st) {
         sa[c] = sa[c - 1] + i.c;
        c++;
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &d);
        l = 1, h = st.size();
        while (l <= h) {
            md = (h + l) / 2;
            (st[md - 1].d > d) ? h = md - 1 : l = md + 1;
        }
        printf("%d\n", sa[l - 1]);
    }
    return 0;
}