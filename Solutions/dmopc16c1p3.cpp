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

double dp[10005] = {0}; int arr[10005] = {};

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        if (i == 1) dp[i] = arr[i];
        else if (i == 2) dp[i] = min(dp[i - 1] + arr[i], dp[i - 2] + (min( arr[i], arr[i - 1]) / 2.0) + max(arr[i - 1], arr[i]));
        else dp[i] = min(min(dp[i - 2] + (min( arr[i], arr[i - 1]) / 2.0) + max(arr[i - 1], arr[i]), dp[i - 3] + arr[i - 1] + arr[i] + arr[i - 2] - min(min(arr[i - 1], arr[i]), arr[i - 2])), dp[i - 1] + arr[i]);
    }
    printf("%.1f\n", dp[n]);
    return 0;
}