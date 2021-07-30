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
#define qu queue
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

pii ppl[200005];

ll cost(int x, int n) {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (x < ppl[i].fs - ppl[i].sc.sc) ans += (ll) (ppl[i].fs - ppl[i].sc.sc - x) * ppl[i].sc.fs;
        if (x > ppl[i].fs + ppl[i].sc.sc) ans += (ll) (x - (ppl[i].fs + ppl[i].sc.sc)) * ppl[i].sc.fs;
    }
    return ans;
}

int main() {
    int n, p, w, d, l = 0, r = 1000000001, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &ppl[i].fs, &ppl[i].sc.fs, &ppl[i].sc.sc);
    }
    while (l < r) {
        m = (l + r) / 2;
        if (cost (m, n) < cost(m + 1, n)) r = m;
        else l = m + 1;
    }
    printf("%lld\n", cost(l, n));
    return 0;
}