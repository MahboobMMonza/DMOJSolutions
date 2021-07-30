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

const ll PRIME = 9223372036854775783, BASE = 26;

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

map<pi, int> cc;
map<pi, bool> cl;

int main() {
    fio;
    int n, x, y, c = 0, dir[]{1, 0, -1, 0, 0, -1, 0, 1};
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        cl[{x, y}] = 1;
        for (int j = 0; j < 8; j += 2) {
            cc[{x + dir[j], y + dir[j + 1]}]++;
            if (cl[{x + dir[j], y + dir[j + 1]}]) {
                if (cc[{x + dir[j], y + dir[j + 1]}] == 3) c++;
                else if (cc[{x + dir[j], y + dir[j + 1]}] > 3) c--;
            }
        }
        cout << c << '\n';
    }
    return 0;
}