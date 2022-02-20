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

int dp[1005][1005]{};

int editDist(const int & n, const int & m, const string & a, const string & b) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (!i) {
                if (j) {
                    dp[i][j] = dp[i][j - 1] + 1;
                    if (j >= 2) dp[i][j] = min(dp[i][j], dp[i][j - 2] + 1);
                    if (j >= 3) dp[i][j] = min(dp[i][j], dp[i][j - 3] + 1);
                }
            } else {
                if (!j) {
                    dp[i][j] = dp[i - 1][j] + 1;
                    if (i >= 2) dp[i][j] = min(dp[i][j], dp[i - 2][j] + 1);
                    if (i >= 3) dp[i][j] = min(dp[i][j], dp[i - 3][j] + 1);
                } else {
                    int rep = a[i - 1] == b[j - 1] ? dp[i - 1][j - 1] : 1 + dp[i - 1][j - 1], del = dp[i - 1][j] + 1,
                    ins = dp[i][j - 1] + 1;
                    if (i >= 2) {
                        del = min(del, dp[i - 2][j] + 1);
                    }
                    if (i >= 3) {
                        del = min(del, dp[i - 3][j] + 1);
                    }
                    if (j >= 2) {
                        ins = min(ins, dp[i][j - 2] + 1);
                    }
                    if (j >= 3) {
                        ins = min(ins, dp[i][j - 3] + 1);
                    }
                    dp[i][j] = min(min(ins, del), rep);
                }
            }
        }
    }
    return dp[n][m];
}

int main() {
    fio;
    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;
    int ans = editDist(n, m, a, b);
    if (ans == 5) cout << a << " " << b << '\n';
    cout << ans << '\n';
    return 0;
}