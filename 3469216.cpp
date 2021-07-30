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
#define MOD % ((ll) 1e9+7)

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

ll arr[100005] {};

int main() {
    fio;
    ll N, M, c = 0;
    cin >> N >> M;
    int l = 0, r = N - 1;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    while (l < r) {
        if (arr[l] + arr[r] <= M) {
            c += r - l;
            l++;
        } else r--;
    }
    cout << (c MOD);
}