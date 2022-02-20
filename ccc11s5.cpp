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
#define sz size()
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

unordered_set<int> v;

int main() {
    fio;
    int n, x;
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x) s |= 1 << i;
    }
    v.insert(s);
    qu<pi> q;
    q.ps({s, 0});
    while (!q.empty()) {
        pi p = q.fr;
        q.pp;
        for (int i = 0; i < n; i++) {
            if (!(1 << i & p.fs) && !v.count(p.fs | 1 << i)) {
                s = p.fs;
                s |= 1 << i;
                bool prv = 0;
                int cnt = 0, f = 100, e = 0;
                for (int j = 0; j < n; j++) {
                    if (!prv && (1 << j & s)) {
                        cnt++;
                        prv = 1;
                        f = j;
                    } else if (prv && (1 << j & s)) {
                        cnt++;
                        if (cnt > 3) { e = j; }
                    } else if (!(1 << j & s)) {
                        prv = 0;
                        if (cnt > 3) {
                            break;
                        } else {
                            cnt = 0, f = 100, e = 0;
                        }
                    }
                }
                for (int j = f; j <= e; j++) {
                    s -= 1 << j;
                }
                v.insert(s);
                if (s == 0) {
                    cout << p.sc + 1 << '\n';
                    return 0;
                }
                q.ps({s, p.sc + 1});
            }
        }
    }
    return 0;
}