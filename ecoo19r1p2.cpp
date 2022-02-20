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

ll fq[26]{}, nf[26]{};
string rule[26]{};

int main() {
    fio;
    string A, c, s;
    char idx;
    int T, R;
    ll l;
    for (int z = 0; z < 10; z++) {
        cin >> R >> T >> A;
        l = 0;
        memset(fq, 0, sizeof fq);
        c = "";
        c.push_back(A[0]);
        c.push_back(A.back());
        for (int r = 0; r < R; r++) {
            cin >> idx >> s;
            rule[idx - 'A'] = s;
        }
        for (char i : A) {
            fq[i - 'A']++;
        }
        for (int t = 0; t < T; t++) {
            memset(nf, 0, sizeof nf);
            s = "";
            s.push_back(rule[c[0] - 'A'].front());
            s.push_back(rule[c[1] - 'A'].back());
            c = s;
            for (int i = 0; i < 26; i++) {
                for (int j = 0; fq[i] && j < rule[i].length(); j++) {
                    nf[rule[i][j] - 'A'] += fq[i];
                }
            }
            memcpy(fq, nf, sizeof fq);
        }
        for (ll i : fq) l += i;
        cout << c << ' ' << l << '\n';
    }
    return 0;
}