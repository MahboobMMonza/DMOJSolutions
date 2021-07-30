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

int isp(const string &s, int l, int r) {
    for (int i = 0; i <= (r - l) / 2; i++) {
        if (s[l + i] != s[r - i]) return 0;
    }
    return 1;
}

int score[5005]{};
int p[5005][35][35]{};
string strs[5005];
set<pi> ins;

int main() {
    fio;
    int n, m, s, a = 0;
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    for (int i = 0; i < s; i++) {
        for (int j = i; j < s; j++) {
            for (int k = 0; k < n; k++) {
                p[k][i + 1][j + 1] = isp(strs[k], i, j);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        ins.insert({l, r});
    }
    for (pi x : ins) {
        for (int j = 0; j < n; j++) {
            score[j] += p[j][x.fs][x.sc];
        }
    }
    for (int i = 0; i < n; i++) {
        a += score[i] == ins.size();
    }
    cout << a << '\n';
    return 0;
}