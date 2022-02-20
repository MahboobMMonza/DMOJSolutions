#include <bits/stdc++.h>

using namespace std;
struct p {
    int x, y, d;
};
int b[9][9] = {0};

int main() {
    int x, y, x2, y2;
    scanf("%d%d%d%d", &x, &y, &x2, &y2);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            b[i][j] = INT_MAX;
        }
    }
    b[x][y] = 0;
    if (x + 2 < 9) {
        if (y + 1 < 9) b[x + 2][y + 1] = 1;
        if (y - 1 > 0) b[x + 2][y - 1] = 1;
    }
    if (x - 2 > 0) {
        if (y + 1 < 9) b[x - 2][y + 1] = 1;
        if (y - 1 > 0) b[x - 2][y - 1] = 1;
    }
    if (y + 2 < 9) {
        if (x + 1 < 9) b[x + 1][y + 2] = 1;
        if (x - 1 > 0) b[x - 1][y + 2] = 1;
    }
    if (y - 2 > 0) {
        if (x + 1 < 9) b[x + 1][y - 2] = 1;
        if (x - 1 > 0) b[x - 1][y - 2] = 1;
    }
    do {
        for (int i = 1; i < 9; i++) {
            for (int j = 1; j < 9; j++) {
                if (b[i][j] != INT_MAX) {
                    if (i + 2 < 9) {
                        if (j + 1 < 9) b[i + 2][j + 1] = min(b[i + 2][j + 1], b[i][j] + 1);
                        if (j - 1 > 0) b[i + 2][j - 1] = min(b[i + 2][j - 1], b[i][j] + 1);
                    }
                    if (i - 2 > 0) {
                        if (j + 1 < 9) b[i - 2][j + 1] = min(b[i - 2][j + 1], b[i][j] + 1);
                        if (j - 1 > 0) b[i - 2][j - 1] = min(b[i - 2][j - 1], b[i][j] + 1);
                    }
                    if (j + 2 < 9) {
                        if (i + 1 < 9) b[i + 1][j + 2] = min(b[i + 1][j + 2], b[i][j] + 1);
                        if (i - 1 > 0) b[i - 1][j + 2] = min(b[i - 1][j + 2], b[i][j] + 1);
                    }
                    if (j - 2 > 0) {
                        if (i + 1 < 9) b[i + 1][j - 2] = min(b[i + 1][j - 2], b[i][j] + 1);
                        if (i - 1 > 0) b[i - 1][j - 2] = min(b[i - 1][j - 2], b[i][j] + 1);
                    }
                }
            }
        }
    } while (b[x2][y2] == INT_MAX);
    printf("%d", b[x2][y2]);
    return 0;
}