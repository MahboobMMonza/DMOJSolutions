#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ppb pop_back
#define fr front()
#define bk back()
#define sbf setbuf(stdout, 0)
#define ppf pop_front()
#define tp top()
#define ps push
#define pp pop()

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

bool cmp(pi const& x, pi const& y) {
    return (x.fs == y.fs) ? x.sc < y.sc : x.fs < y.fs;
}

int main() {
    vector<pi> pl;
    int n, p, f, c;
    ll a = 1, ff = 0;
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &f, &c);
        if (i != p) {
            pl.eb(f, c);
        } else {
            ff += f;
        }
    }
    sort(pl.begin(), pl.end(), cmp);
    for (auto& x : pl) {
        if (x.sc <= x.fs && ff >= x.sc) {
            ff += x.fs - x.sc;
            a++;
        }
    }
    sbf;
    printf("%lld\n%lld\n", ff, a);
    return 0;
}