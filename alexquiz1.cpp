#include <bits/stdc++.h>

using namespace std;

#define fs first
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

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pl;
typedef pair<ull, ull> pull;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

int reduce(int x, int n) {
    while (x > n) x >>= 1;
    return x;
}

ll dp[1005] = {};
pil arr[1005] = {};

int main() {
    int N, M, K, t, d, a;
    ll q;
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; ++i) {
        scanf("%d%lld", &arr[i].fs, &arr[i].sc);
    }
    for (int i = 0; i < M; ++i) {
        scanf("%lld%d%d%d", &q, &t, &d, &a);
        int x = 1;
        while (a) {
            for (int j = K; j >= x * d; j--) {
                dp[j] = max(dp[j], dp[j - (x * d)] + (q * x * arr[t].sc));
            }
            a -= x;
            x = (a >= x * 2) ? x << 1 : (a >= x) ? x + 0 : reduce(x, a);
        }
    }
    for (int i = 0; i <= K; ++i) {
        for (int j = 1; j <= N; j++) {
            if (arr[j].fs <= i) dp[i] = max(dp[i], dp[i - arr[j].fs] + arr[j].sc);
        }
    }
    printf("%lld\n", dp[K]);
    return 0;
}