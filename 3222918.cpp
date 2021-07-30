#include <bits/stdc++.h>

using namespace std;

bool b[101][101] = {0};
int main() {
    int n, m, x, y, t;
    scanf("%d%d", &n, &m);
    t = n * n;
    while (m--) {
        scanf("%d%d", &x, &y);
        for (int i = 1; i <= n; i++) {
            if (!b[i][y]) {
                b[i][y] = 1;
                t--; 
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!b[x][i]) {
                b[x][i] = 1;
                t--; 
            }
        }
        for (int i = x, j = y; i > 0 && j <= n; i--, j++) {
            if (!b[i][j]) {
                b[i][j] = 1;
                t--;
            }
        }
        for (int i = x, j = y; j > 0 && i <= n; i++, j--) {
            if (!b[i][j]) {
                b[i][j] = 1;
                t--;
            }
        }
        for (int i = x, j = y; i > 0 && j > 0; i--, j--) {
            if (!b[i][j]) {
                b[i][j] = 1;
                t--;
            }
        }
        for (int i = x, j = y; i <= n && j <= n; i++, j++) {
            if (!b[i][j]) {
                b[i][j] = 1;
                t--;
            }
        }
    }
    printf("%d", t);
    return 0;
}