#include <bits/stdc++.h>
using namespace std;

bool cat[26][26] = {0};
int dp[26][26] = {0};
int main() {
    int r, c, x, y, t;
    scanf("%d%d%d", &r, &c, &t);
    while (t--) {
        scanf("%d%d", &x, &y);
        cat[x][y] = 1;
        dp[x][y] = 0;
    }
    cat[1][1] = 1;
    dp[1][1] = 1;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (!cat[i][j]) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    printf("%d", dp[r][c]);
    return 0;
}