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

inline ll mulMod(ll x, ll y, ll m = LONG_LONG_MAX) { x %= m; ll res = 0; while (y) { if (y & 1) res = (res + x) % m; if (res < 0) res += m; x = (x << 1) % m; y >>= 1; } return res % m; }
inline ll logPow(ll x, ll y, ll m = LONG_LONG_MAX) { x %= m; ll res = 1; while (y) {if (y & 1) res = mulMod(res, x, m); x = mulMod(x, x, m); y >>= 1; } return res % m; }
inline ll pLogPow(ll x, ll y, ll m = 9223372036854775783) { return logPow(x, y % (m - 1), m); }

bool bs[2010][2010] {};
vector<pci> ans;

int sol(const int & n) {
    for (int i = 1; i <= n; i++) {
        if (bs[1][i]) {
            ans.eb('C', i);
            for (int j = 1; j <= n; j++) {
                bs[j][i] = !bs[j][i];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (bs[i][1]) {
            ans.eb('R', i);
            for (int j = 1; j <= n; j++) {
                bs[i][j] = !bs[i][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (bs[i][j]) {cout << "-1\n"; return 0; }
        }
    }
    return 1;
}

int main() {
    fio;
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> x; bs[i][j] = x;
        }
    }
    if (sol(n)) {
        cout << ans.size() << '\n';
        for (auto & p : ans) {
            cout << p.fs << ' ' << p.sc << '\n';
        }
    }
    return 0;
}