#include <bits/stdc++.h>

using namespace std;

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