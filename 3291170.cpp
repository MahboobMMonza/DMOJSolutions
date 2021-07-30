#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
bool v[1003 * 1003] = {false};
int g[10001][10001];
int main() {
    int m, n;
    stack<pii> l;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &g[i][j]);
        }
    }
    pii p = make_pair(1, 1);
    v[1 * n + 1] = true;
    l.push(p);
    int x;
    while (!l.empty()) {
        p = l.top(); l.pop();
        x = g[p.first][p.second];
        for (int i = 1; i * i <= x; ++i) {
            if (x % i == 0) {
                if (x / i <= m && i <= n && !v[(x / i) * n + i]) {
                    v[(x / i) * n + i] = 1;
                    if (x / i == m && i == n) {
                        printf("yes\n");
                        return 0;
                    }
                    l.push(make_pair(x / i, i));
                }
                if (i <= m && x / i <= n && !v[(i * n) + (x / i)]) {
                    v[(i * n) + (x / i)] = 1;
                    if (i == m && x / i == n) {
                        printf("yes\n");
                        return 0;
                    }
                    l.push(make_pair(i, x / i));
                }
            }
        }
    }
    printf("no\n");
    return 0;
}