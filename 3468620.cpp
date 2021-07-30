#include <bits/stdc++.h>

using namespace std;

#define fs first
#define fio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
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

inline ll mulMod(ll x, ll y, ll m = LONG_LONG_MAX) { x %= m; ll res = 0; while (y) { if (y & 1) res = (res + x) % m; x = (x << 1) % m; y >>= 1; } return res % m; }
inline ll logPow(ll x, ll y, ll m = LONG_LONG_MAX) { x %= m; ll res = 1; while (y) {if (y & 1) res = mulMod(res, x, m); x = mulMod(x, x, m); y >>= 1; } return res % m; }
inline ll pLogPow(ll x, ll y, ll m = 9223372036854775783) { return logPow(x, y % (m - 1), m); }

int dp[105]{}, q[105]{}, o[105]{};

int main() {
    fio;
    vector<string> n;
    stack<string> g;
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    int M, Q;
    string s;
    cin >> M >> Q;
    n.eb("START");
    for (int i = 1; i <= Q; i++) {
        cin >> s >> q[i];
        n.pb(s);
        if (i == 1) {
            dp[i] = q[i];
        } else {
            for (int j = 1; j <= M && i - j >= 0; j++) {
                int c = 0;
                for (int k = 0; k < j; k++) {
                    c = max(q[i - k], c);
                }
                if (dp[i - j] + c < dp[i]) {
                    o[i] = i - j;
                    dp[i] = c + dp[i - j];
                }
            }
        }
    }
    cout << "Total Time: " << dp[Q];
    for (int i = Q; i > 0; i = o[i]) {
        for (int j = i; j > o[i]; j--) {
            g.ps(n[j] + " ");
        }
        g.ps("\n");
    }
    while (!g.empty()) {
        cout << g.tp; g.pp;
    }
    return 0;
}