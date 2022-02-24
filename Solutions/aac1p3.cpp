#include <bits/stdc++.h>

using namespace std;

#define fs first
#define fio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sc second
#define pb push_back
#define eb emplace_back
#define edl '\n'
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
#define fora(i, a, b, c) for (int (i) = (a); (i) < (b); (i) += (c))
#define forae(i, a, b, c) for (int (i) = (a); (i) <= (b); (i) += (c))
#define ford(i, a, b, c) for (int (i) = (a); (i) > (b); (i) -= (c))
#define forde(i, a, b, c) for (int (i) = (a); (i) >= (b); (i) -= (c))
#define dblinf numeric_limits<double>::infinity()

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pl;
typedef pair<ull, ull> pull;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;
typedef pair<pi, pi> ppi;
typedef pair<double, double> pd;
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

inline ll fsLogPow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

inline ll pLogPow(ll x, ll y, ll m = 9223372036854775783) { return logPow(x, y % (m - 1), m); }

int main() {
    fio;
    // Odd N -> 0 = -1 Impossible
    // N = 2 X = 1 ==> -1
    // Even N even X
    // 10 4
    // 0 0 0 0 0 1 0 1 0 1
    // Even N odd X impossible
    // Odd N even X impossible
    // Odd N odd X
    // 9 5
    // 0 0 0 0 0 0 1 0 1
    int n, x;
    cin >> n >> x;
    vector<int> nums(n, 0);
    if ((n - x) % 2 != 0) {
        cout << -1 << edl;
        return 0;
    } else if (n % 2 == 0) {
        fora(i, x + 1, n, 1) {
            nums[i] = (i % 2);
        }
    } else {
        fora(i, x + 1, n, 1) {
            nums[i] = (i - 1) % 2;
        }
    }
    cout << nums[0];
    fora(i, 1, n, 1) {
        cout << ' ' << nums[i];
    }
    cout << edl;
    return 0;
}