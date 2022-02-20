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

int psa[405]{};
bool dp[405][405]{};

int main() {
    fio;
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> psa[i];
        ans = max(psa[i], ans);
        dp[i][i] = 1;
        psa[i] += psa[i - 1];
    }
    for (int len = 1; len < n; len++) {
        for (int l = 1; l + len <= n; l++) {
            int r = l + len;
            for (int p = l, q = r; p < q;) {
                int sl = psa[p] - psa[l - 1], sr = psa[r] - psa[q - 1];
                if (dp[l][p] && dp[q][r] && sl == sr  && (p + 1 == q || dp[p + 1][q - 1])) {
                    dp[l][r] = 1;
                }
                if (dp[l][r]) ans = max(ans, psa[r] - psa[l - 1]);
                if (sl < sr) p++;
                else q--;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}