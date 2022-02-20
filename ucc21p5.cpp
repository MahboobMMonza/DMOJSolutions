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
typedef pair <ll, ll> pl;
typedef pair <ull, ull> pull;
typedef pair<int, pi> pii;
typedef pair <ll, pl> pll;
typedef pair <pi, pi> ppi;
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

int dp[3][301][3][301]{};

int game(int h1, int w1, int h2, int w2) {
    if (dp[h1][w1][h2][w2] + 1) return dp[h1][w1][h2][w2];
    int ret = 0;
    for (int i = 1; i < h1; i++) ret |= (!(game(i, w1, h1 - i, w1)) | !game(i, w1, h2, w2));
    for (int i = 1; i < h2; i++) ret |= (!(game(i, w2, h2 - i, w2)) | !game(h1, w1, i, w2));
    for (int i = 1; i < w1; i++) ret |= !game(h1, i, h1, w1-i);
    for (int i = 1; i < w2; i++) ret |= !game(h2, i, h2, w2 - i);
    for (int i = 1; i <= 10 && i < w1; i++) ret |= !game(h1, w1 - i, h2, w2);
    for (int i = 1; i <= 10 && i < w2; i++) ret |= !game(h1, w1, h2, w2 - i);
    return dp[h1][w1][h2][w2] = ret;
}

int main() {
    fio;
    memset(dp, -1, sizeof dp);
    int h1, h2, w1, w2;
    dp[1][1][1][1] = 0;
    cin >> h1 >> w1 >> h2 >> w2;
    cout << (game(h1, w1, h2, w2) ? 'W' : 'L') << '\n';
    return 0;
}