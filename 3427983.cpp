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
typedef pair<ull, ull> pull;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;

int dp[100005] = {0}, arr[2][100005] = {};

int main() {
    int n;
    scanf("%d", &n);
    for (int _ = 0; _ < 2; _++) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &arr[_][i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1) dp[i] = max(arr[0][i], arr[1][i]);
        else if (i == 2) dp[i] = max(arr[0][i] + dp[i - 1], arr[1][i] + dp[i - 1]);
        else dp[i] = max(max(arr[1][i] + dp[i - 1], arr[0][i] + arr[0][i - 1] + arr[1][i - 2] + dp[i - 3]), arr[0][i] + arr[1][i - 1] + dp[i - 2]);
    }
    printf("%d", dp[n]);
    return 0;
}