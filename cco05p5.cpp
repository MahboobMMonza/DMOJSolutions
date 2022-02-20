#include <bits/stdc++.h>

using namespace std;

#define fs first
#define fio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sc second
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ppb pop_back()
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
typedef pair<char, int> pci;

inline ll mulMod(ll x, ll y, ll m = LONG_LONG_MAX) {
    x %= m;
    ll res = 0;
    while (y) {
        if (y & 1) res = (res + x) % m;
        if (res < 0) res += m;
        x = (x << 1) % m;
        y >>= 1;
    }
    return res % m;
}

inline ll logPow(ll x, ll y, ll m = LONG_LONG_MAX) {
    x %= m;
    ll res = 1;
    while (y) {
        if (y & 1) res = mulMod(res, x, m);
        x = mulMod(x, x, m);
        y >>= 1;
    }
    return res % m;
}

inline ll pLogPow(ll x, ll y, ll m = 9223372036854775783) { return logPow(x, y % (m - 1), m); }

const int MAX = 20005;

int a[MAX]{}, b[MAX]{}, c[MAX]{}, d[MAX]{};

int main() {
    fio;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    c[0] = (b[0] - 1) + (b[0] - a[0]);
    d[0] = (b[0] - 1);
    for (int i = 1; i < n; ++i) {
        d[i] = b[i] - a[i] + min(c[i - 1] + abs(a[i] - a[i - 1]), d[i - 1] + abs(a[i] - b[i - 1]));
        c[i] = b[i] - a[i] + min(d[i - 1] + abs(b[i] - b[i - 1]), c[i - 1] + abs(b[i] - a[i - 1]));
    }
    cout << min(n - b[n - 1] + d[n - 1], n - a[n - 1] + c[n - 1]) + n - 1 << '\n';
    return 0;
}