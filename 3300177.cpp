#include <bits/stdc++.h>

using namespace std;
int fl[2][101];
int main() {
    int n, ans = 0;
    double av;
    scanf("%d", &n);
    ans += n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &fl[0][i]);
        fl[1][i] = fl[0][i] + fl[1][i - 1];
    }
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            av = (fl[1][j] - fl[1][i - 1] + 0.0) / (j - i + 1.0);
            for (int k = i; k <= j; k++) {
                if (fl[0][k] + 0.0 == av) {
                    ans++;
                    break;
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}