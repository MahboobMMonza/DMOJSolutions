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

int dp[258][260] = {};
char s[257];
string g[258];
int main() {
    int n, ans;
    for (int t = 0; t < 5; t++) {
        scanf("%d", &n);
        memset(dp, 0, sizeof dp);
        ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            g[i] = "." + string(s) + ".";
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j < n + 2; j++) {
                if (g[i][j] == '#') ans += (dp[i][j] = min(min(dp[i + 1][j - 1], dp[i + 1][j]), dp[i + 1][j + 1]) + 1);
            }
        }
        printf("%lld\n", ans);
    }
}