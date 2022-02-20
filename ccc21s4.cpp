#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define fr front()
#define bk back()
#define sbf setbuf(stdout, 0)
#define ppf pop_front()
#define tp top()
#define ps push
#define pp pop()
#define fls fflush(stdout)
#define qu queue
#define st stack
#define pq priority_queue

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pl;
typedef pair<ull, ull> pull;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;
typedef pair<pi, pi> ppi;

struct sta {
    int rd = 0x3f3f3f3f, idx = 0;
    vector<int> adj;
} sub[200005] {};

int tr[200005] {};

int main() {
    set<pi> bst;
    int n, w, d, a, b;
    scanf("%d%d%d", &n, &w, &d);
    for (int i = 0; i < w; i++) {
        scanf("%d%d", &a, &b);
        sub[b].adj.pb(a);
    }
    qu<pi> q;
    sub[n].rd = 0;
    q.ps({0, n});
    while (!q.empty()) {
        pi x = q.fr; q.pp;
        for (auto & i : sub[x.sc].adj) {
            if (sub[i].rd > x.fs + 1) {
                sub[i].rd = x.fs + 1;
                q.ps({x.fs + 1, i});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tr[i]);
        sub[tr[i]].idx = i - 1;
        bst.insert({i - 1 + sub[tr[i]].rd, tr[i]});
    }
    for (int i = 0; i < d; i++) {
        scanf("%d%d", &a, &b);
        bst.erase({sub[tr[a]].idx + sub[tr[a]].rd, tr[a]});
        bst.erase({sub[tr[b]].idx + sub[tr[b]].rd, tr[b]});
        swap(sub[tr[a]].idx, sub[tr[b]].idx);
        swap(tr[a], tr[b]);
        bst.insert({sub[tr[a]].idx + sub[tr[a]].rd, tr[a]});
        bst.insert({sub[tr[b]].idx + sub[tr[b]].rd, tr[b]});
        printf("%d\n", bst.begin()->fs);
    }
    return 0;
}