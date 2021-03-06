#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define fr front()
#define bk back()
#define ppf pop_front()
#define tp top()
#define ps push
#define pp pop()

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

pl tr[5005] = {};
ll dp[5005] = {};

int reduce(int x, int n) {
    while (x > n) x /= 2;
    return x;
}

int main() {
    int N, M;
    ll n, p, v, a = 0;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%lld%lld%lld", &n, &v, &p);
        ll x = 1;
        while (n > 0) {
            pl gd = {x * p, x * v};
            n -= x;
            (n >= x * 2) ? x *= 2 : (n >= x) ? x += 0 : x = reduce(x, n);
            for (int j = 5000; j >= gd.sc; j--) {
                dp[j] = max(dp[j], dp[j - gd.sc] + gd.fs);
            }
        }
    }
    for (int i = 0; i < M; i++) {
        scanf("%lld%lld", &tr[i].fs, &tr[i].sc);
        if (i == 0) {
            a = dp[tr[i].fs] - tr[i].sc;
        } else {
            a = max(a, dp[tr[i].fs] - tr[i].sc);
        }
    }
    printf("%lld\n", a);
}