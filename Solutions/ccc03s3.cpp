#include <bits/stdc++.h>

using namespace std;

#define fs first
#define fio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sc second
#define pb push_back
#define eb emplace_back
#define endl '\n'
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

bool traversable(int r, int c, int in, int jn) {
    return 0 <= in && r > in && 0 <= jn && c > jn;
}

int fill(int i, int j, int r, int c, vector<vector<int>> &g) {
    qu<int> q;
    int sz = 0;
    q.push(i);
    q.push(j);
    g[i][j] = 1;
    sz++;
    while (!q.empty()) {
        i = q.front();
        q.pop();
        j = q.front();
        q.pop();
        if (traversable(r, c, i - 1, j) && !g[i - 1][j]) {
            q.push(i - 1);
            q.push(j);
            sz++;
            g[i - 1][j] = 1;
        }
        if (traversable(r, c, i + 1, j) && !g[i + 1][j]) {
            q.push(i + 1);
            q.push(j);
            sz++;
            g[i + 1][j] = 1;
        }
        if (traversable(r, c, i, j - 1) && !g[i][j - 1]) {
            q.push(i);
            q.push(j - 1);
            sz++;
            g[i][j - 1] = 1;
        }
        if (traversable(r, c, i, j + 1) && !g[i][j + 1]) {
            q.push(i);
            q.push(j + 1);
            sz++;
            g[i][j + 1] = 1;
        }
    }
    return sz;
}

int main() {
    fio;
    vector<vector<int>> g(25, vector<int>(25));
    vector<int> sources;
    vector<int> rooms;
    int fl, r, c, rm = 0, sz;
    cin >> fl >> r >> c;
    string line;
    for (int i = 0; i < r; ++i) {
        cin >> line;
        for (int j = 0; j < c; ++j) {
            g[i][j] = line[j] == 'I' ? -1 : 0;
            if (i > 0 && i < r - 1 && j > 0 && j < c - 1) {
                if (g[i - 1][j] == -1 && g[i][j - 1] == -1 && g[i][j] == 0) {
                    sources.pb(i);
                    sources.pb(j);
                }
            }
            if (((j == 0 || j == c - 1) || (i == 0 || i == r - 1)) && g[i][j] == 0) {
                sources.pb(i);
                sources.pb(j);
            }
        }
    }
    for (int i = 0; i < sources.size(); i += 2) {
        if (g[sources[i]][sources[i + 1]] == 0) {
            sz = fill(sources[i], sources[i + 1], r, c, g);
            rooms.push_back(sz);
        }
    }
    sort(rooms.begin(), rooms.end());
    for (int i = rooms.size() - 1; i >= 0; i--) {
        fl -= rooms[i];
        if (fl < 0) {
            fl += rooms[i];
            break;
        }
        rm++;
    }
    cout << rm << (rm == 1 ? " room" : " rooms") << ", " << fl << " square metre(s) left over" << endl;
}