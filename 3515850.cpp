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

ll s[1000005]{};
pll o[1000005]{};
int n, m;

bool p(int x) {
    vector<int> v(n + 5, 0);
    for (int i = 1; i <= x; i++) {
        v[o[i].sc.fs] += o[i].fs;
        v[o[i].sc.sc + 1] -= o[i].fs;
    }
    for (int i = 1; i <= n; i++) {
        v[i] += v[i - 1];
        if (v[i] > s[i])
            return 0;
    }
    return 1;
}

pi bs() {
    int l = 1, r = m;
    while (l < r) {
        int mid = (r - l)/2 + l;
        p(mid) ? l = mid + 1 : r = mid;
    }
    if (l == m && p(l)) return {0,0};
    return {-1, l};
}

int main() {
    fio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> o[i].fs >> o[i].sc.fs >> o[i].sc.sc;
    }
    pi ans = bs();
    ans.fs == 0 ? cout << "0\n" : cout << ans.fs << '\n' << ans.sc;
    return 0;
}