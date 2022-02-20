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

int dp[501][30005] = {}, p[30005] = {};

int main() {
    int t, n, k, w;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &k, &w);
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
            p[i] += p[i - 1];
        }
        for (int b = 1; b <= k; b++) {
            for (int i = 1; i <= n; i++) {
                dp[b][i] = (i <= w) ? p[i] : max(dp[b - 1][i - w] + p[i] - p[i - w], dp[b][i - 1]);
            }
        }
        printf("%d\n", dp[k][n]);
    }
}