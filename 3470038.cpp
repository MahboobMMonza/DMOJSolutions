#include <bits/stdc++.h>

using namespace std;

#define fs first
#define fio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
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

inline ll mulMod(ll x, ll y, ll m = LONG_LONG_MAX) { x %= m; ll res = 0; while (y) { if (y & 1) res = (res + x) % m; x = (x << 1) % m; y >>= 1; } return res % m; }
inline ll logPow(ll x, ll y, ll m = LONG_LONG_MAX) { x %= m; ll res = 1; while (y) {if (y & 1) res = mulMod(res, x, m); x = mulMod(x, x, m); y >>= 1; } return res % m; }
inline ll pLogPow(ll x, ll y, ll m = 9223372036854775783) { return logPow(x, y % (m - 1), m); }

ll dp[10005]{};
pl pv[3]{};

int main() {
    fio;
    int N, T;
    cin >> N >> T;
    while (N--) {
        for (int i = 0; i < 3; i++) {
            cin >> pv[i].fs >> pv[i].sc;
        }
        for (int j = T; j >= pv[0].fs; j--) {
                if (j >= pv[0].fs) dp[j] = max(dp[j], dp[j - pv[0].fs] + pv[0].sc);
                if (j >= pv[1].fs) dp[j] = max(dp[j], dp[j - pv[1].fs] + pv[1].sc);
                if (j >= pv[2].fs) dp[j] = max(dp[j], dp[j - pv[2].fs] + pv[2].sc);
        }
    }
    cout << dp[T] << '\n';
    return 0;
}