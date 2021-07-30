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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

ll dp[3][100005]{};

int main() {
    ll n, a, b, c;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + c;
        dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + b;
        dp[0][i] = max(dp[2][i - 1], dp[1][i - 1]) + a;
    }
    printf("%lld\n", max(max(dp[0][n], dp[1][n]), dp[2][n]));
    return 0;
}