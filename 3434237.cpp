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
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

ll sr[2][1005], dp[1005][1005];
char s[1005], t[1005];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 1; i <= n; ++i) scanf("%lld", &sr[0][i]);
    scanf("%s", t);
    for (int i = 1; i <= n; ++i) scanf("%lld", &sr[1][i]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] != t[j - 1] &&
                ((t[j - 1] == 'W' && sr[1][j] > sr[0][i]) || (t[j - 1] == 'L' && sr[1][j] < sr[0][i])))
                dp[i][j] = max(dp[i - 1][j - 1] + sr[0][i] + sr[1][j], max(dp[i - 1][j], dp[i][j - 1]));
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    printf("%lld\n", dp[n][n]);
    return 0;
}