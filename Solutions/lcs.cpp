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


int dp[1001][1001] = {}, na[1001] {}, ma[1001] {};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &na[i]);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &ma[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; ++j) {
            if (na[i] == ma[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}