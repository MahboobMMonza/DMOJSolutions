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

int dp[5281] = {}, c[32] = {};

int main() {
    int d, n;
    scanf("%d%d", &d, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        dp[c[i]] = 1;
    }
    sort(c, c + n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= d; ++j) {
            if (dp[j] != 0 && j + c[i] <= d) {
                dp[j + c[i]] = (dp[j + c[i]] == 0) ? dp[j] + 1 : min(dp[j] + 1, dp[c[i] + j]);
            }
        }
    }
    (dp[d]) ? printf("Roberta wins in %d strokes.\n", dp[d]) : printf("Roberta acknowledges defeat.\n");
}