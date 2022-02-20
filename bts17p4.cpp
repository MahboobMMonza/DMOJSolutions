#include <bits/stdc++.h>

using namespace std;

#define fs first
#define fio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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

pi t[100005]{};

int main() {
    pq<int, vector<int>, greater<>> u;
    fio;
    int N, M, J, c = 0, r = 0, ans = -1;
    cin >> N >> M >> J;
    if (!J) {
        cout << -1 << '\n';
        return 0;
    } else if (J >= N + 1) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 0; i < M; i++) {
        cin >> t[i].sc >> t[i].fs;
    }
    sort(t, t + M, less<>());
    for (int i = 0; i <= t[M - 1].fs; i++) {
        while (i == t[c].fs) {
            u.ps(t[c].sc); c++;
        }
        while (!u.empty() && u.tp - r <= J) {
            r = max(r, u.tp);
            u.pp;
            if (r + J > N) {
                ans = i;
                break;
            }
        }
        if (ans != -1) break;
    }
    cout << ans << '\n';
}