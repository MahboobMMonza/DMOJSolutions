#include <bits/stdc++.h>

using namespace std;

bool row[31000] = {0}, col[31000] = {0};
int main() {
    for (int t = 0; t < 5; t++) {
        int r, c, ro, x, y, count;
        scanf("%d%d%d", &r, &c, &ro);
        for (int i = 0; i < r; i++) {
            row[i] = 0;
        }
        for (int i = 0; i < c; i++) {
            col[i] = false;
        }
        count = r * c;
        while (ro--) {
            scanf("%d%d", &x, &y);
            if (!row[x - 1]) {
                row[x - 1] = 1;
                for (int i = 0; i < c; i++) {
                    if (!col[i]) count--;
                }
            }
            if (!col[y - 1]) {
                col[y - 1] = 1;
                for (int i = 0; i < r; i++) {
                    if (!row[i]) count--;
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}