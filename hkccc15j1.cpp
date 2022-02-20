#include <bits/stdc++.h>

using namespace std;

char shape[9];
int a[2][100] = {0};
int main() {
    int n, x = 0, y = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%s", shape);
            if (shape[0] == 'r') {
                a[i][j] = 0;
            } else if (shape[0] == 'p') {
                a[i][j] = 1;
            } else {
                a[i][j] = 2;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[0][i] == 0) {
            (a[1][i] == 0) ? x += 0 : (a[1][i] == 1) ? y++ : x++;
        }
        if (a[0][i] == 1) {
            (a[1][i] == 1) ? x += 0 : (a[1][i] == 0) ? x++ : y++;
        }
        if (a[0][i] == 2) {
            (a[1][i] == 2) ? x += 0 : (a[1][i] == 0) ? y++ : x++;
        }
    }
    printf("%d %d", x, y);
    return 0;
}