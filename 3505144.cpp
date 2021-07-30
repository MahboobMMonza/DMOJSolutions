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

int n[101]{};
bitset<100005> dp;

int main() {
    fio;
    int T;
    cin >> T;
    while (T--) {
        int N, a = 0;
        dp.reset();
        dp[0] = 1;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> n[i];
        }
        sort(n, n + N);
        for (int i = 0; i < N; i++) {
            if (!dp[n[i]]) {
                a++;
                dp[n[i]] = 1;
            }
            for (int j = 0; j <= n[N - 1] - n[i]; j++) {
                dp[j + n[i]] = dp[j] ? 1 : dp[j + n[i]];
            }
        }
        cout << a << '\n';
    }
    return 0;
}